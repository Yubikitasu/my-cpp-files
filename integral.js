function convertToJSFunction(expr, originalVar = 'x', paramVar = 'a') {
    // Step 1: Handle implicit multiplication (number or closing parenthesis followed by variable or function)
    expr = expr.replace(/(\d|\))(?=[a-zA-Z\(])/g, '$1*');

    // Step 2: Replace ^ with ** for exponentiation
    expr = expr.replace(/\^/g, '**');

    // Step 3: Replace functions with Math equivalents
    const functions = ['sin', 'cos', 'tan', 'log', 'sqrt', 'abs', 'exp', 'asin', 'acos', 'atan'];
    for (const fn of functions) {
        const regex = new RegExp(`\\b${fn}\\b`, 'g');
        expr = expr.replace(regex, `Math.${fn}`);
    }

    // Step 4: Replace the original variable with the new param variable
    const varRegex = new RegExp(`\\b${originalVar}\\b`, 'g');
    expr = expr.replace(varRegex, paramVar);

    return expr;
}


function find_Integral(a, b, inputExpr) {
    const jsExpr = convertToJSFunction(inputExpr);
    const f = new Function('a', `return ${jsExpr};`);
    //using the Riemann formula
    const n = 10**5;
    sum = 0;
    dx = (b - a) / n
    for (i = 1; i <= n; i++) {
        x_i = a + i * dx
        sum += f(x_i) * dx
    }
    return Math.round(sum * 1000) / 1000
}

console.log(find_Integral(0, 0.5, "sin(x)^2 / cos(x) ^ 4"))
