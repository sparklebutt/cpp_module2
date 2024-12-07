/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:06:26 by shaboom           #+#    #+#             */
/*   Updated: 2024/12/07 15:19:16 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int		main() 
{
	if (bsp(Point(3.0, 4.0, "a"), Point(3.0, 7.0, "b"), Point(6.0, 7.0, "c"), Point(5.3, 6.7, "point")) == true)
		std::cout<<"inside the triangle"<<std::endl;
	else
		std::cout<<"not inside the triangle"<<std::endl;
	return 0;
}
/**
 * here lies an example main that will darw some kind of image onto terminal
 * alternativly you can use this websit www.desmos.com for a more visual and 
 * accurate potraying of a triangle, this main was written with copilot purley 
 * to make you , the evaluators life easier by a little bit. it uses the fobidden 
 * library vector 
 */

/*#include <vector>
#include <iostream>
#include <cmath>

const int WIDTH = 20;
const int HEIGHT = 15;

void drawLine(std::vector<std::vector<char>>& grid, int x0, int y0, int x1, int y1, char ch) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;
    
    while (true) {
        if (x0 >= 0 && x0 < WIDTH && y0 >= 0 && y0 < HEIGHT) {
            grid[y0][x0] = ch;
        }
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

void drawMap(const Point& a, const Point& b, const Point& c, const Point& p) {
    std::vector<std::vector<char>> grid(HEIGHT, std::vector<char>(WIDTH, ' '));

    auto mapToGrid = [](float x, float y) -> std::pair<int, int> {
        int gridX = static_cast<int>(x);
        int gridY = HEIGHT - 1 - static_cast<int>(y); // Invert Y for terminal coordinates
        return {gridX, gridY};
    };

    auto [ax, ay] = mapToGrid(a.getX().toFloat(), a.getY().toFloat());
    auto [bx, by] = mapToGrid(b.getX().toFloat(), b.getY().toFloat());
    auto [cx, cy] = mapToGrid(c.getX().toFloat(), c.getY().toFloat());
    auto [px, py] = mapToGrid(p.getX().toFloat(), p.getY().toFloat());

    drawLine(grid, ax, ay, bx, by, '.');
    drawLine(grid, bx, by, cx, cy, '.');
    drawLine(grid, cx, cy, ax, ay, '.');

    if (ax >= 0 && ax < WIDTH && ay >= 0 && ay < HEIGHT) grid[ay][ax] = 'A';
    if (bx >= 0 && bx < WIDTH && by >= 0 && by < HEIGHT) grid[by][bx] = 'B';
    if (cx >= 0 && cx < WIDTH && cy >= 0 && cy < HEIGHT) grid[cy][cx] = 'C';
    if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT) grid[py][px] = 'P';

    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    Point a(3.0, 4.0, "a");
    Point b(3.0, 7.0, "b");
    Point c(6.0, 7.0, "c");
    Point p(5.3, 6.7, "point");

    drawMap(a, b, c, p);

    if (bsp(a, b, c, p)) {
        std::cout << "inside the triangle" << std::endl;
    } else {
        std::cout << "not inside the triangle" << std::endl;
    }

    return 0;
}*/
