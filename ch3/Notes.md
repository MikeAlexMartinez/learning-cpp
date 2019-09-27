# CH3 - Types and Objects


## 3.8 - Types an Object

- A *type* defines a set of possible values and a set of operations (for an object).
- An *object* is some memory that hold a value of a given type.
- A *value* is a set of bits in memory interpreted according to a type.
- A *variable* is a named object.
- a *declaration* is a statement that gives a name to an object.
- A *definition* is a declaration that sets aside memory for an object.

Bits of memory only get memory when we decide to interpret - give meaning - to that memory.

## 3.9 Type Safety

Every object is given a type when defined. A program is type-safe when object are used
only according to the rules for their type.

One should always initialize their variables to avoid errors.

### 3.9.1 Safe Conversions

A safe conversion is where a type can be safely transformed into another without losing
any information.

The following conversions are safe:
- bool to char
- bool to int
- bool to double
- char to int
- char to double
- int to double (one of the most useful)

For really large ints, we can suffer a loss of precision when converting to a double.

### 3.9.2 Unsafe conversions

Sometimes values may be implicitly converted to another value and change the value as a result.
Some conversions exhibit 'narrowing' where a larger value is squeezed into a smaller value, and
as a result loses some information.

C++11 introduced an initialization notation that outlaws narrowing conversions. E.g.

```c++
double x {2.7};  // OK
int y {x};       // error: double -> int might narrow
```

This {}-list-based notation is known as universal and uniform initialization.

