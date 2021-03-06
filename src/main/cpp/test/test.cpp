/*
 * This file is part of the Kentside Minimal Test Harness
 *
 * Copyright (C) 2017 Helm Solutions Ltd (kentside@yandex.com)
 *
 * The Kentside Minimal Test Harness is free software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * The Kentside Minimal Test Harness is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Kentside Minimal Test Harness.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include <exception>

#include "test/test.hpp"
#include "test/testFailure.hpp"
#include "test/testResult.hpp"

void test::test::run_test(test_result& results) {
    try {
        results.start(_name);
        (*this)();
        results.success(_name);
    }
    catch (const test_failure& tf) {
        results.failure(_name, tf.what());
    }
    catch (const std::exception& se) {
        results.error(_name, se.what());
    }
    catch (...) {
        results.error(_name, "Unknown exception");
    }
}

