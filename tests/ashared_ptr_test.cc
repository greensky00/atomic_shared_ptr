/**
 * Copyright (C) 2017-present Jung-Sang Ahn <jungsang.ahn@gmail.com>
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>

#include "ashared_ptr.h"

struct temp {
    temp(int aa, int bb) : a(aa), b(bb) {}
    int a;
    int b;
};

ashared_ptr<temp> func1() {
    ashared_ptr<temp> ta_ptr(new temp(1, 2));
    ashared_ptr<temp> tb_ptr(new temp(3, 4));

    temp aa = *ta_ptr;
    (void)aa;

    return tb_ptr;
}

void func2() {
    ashared_ptr<temp> tb_ptr = nullptr;
}

int main() {
    ashared_ptr<temp> a = func1();

    func2();

    ashared_ptr<temp> b(new temp(5, 6));
    b = a;

    ashared_ptr<temp> c(new temp(7, 8));
    ashared_ptr<temp> d = c;

    ashared_ptr<temp> e(new temp(0, 0));
    c.compare_exchange(e, b);
    c.compare_exchange(d, b);

    e.reset();

    // NULL set
    ashared_ptr<temp> f = e;
    f.reset();

    return 0;
}
