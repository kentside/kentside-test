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

#include "test/testRegistrar.h"
#include "test/testRegistry.h"

test::test_registry* test::test_registry::_instance;

test::test_registrar::test_registrar(test* test) {
    test_registry::instance().add_test(test);
}

