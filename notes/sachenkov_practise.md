# second practise

## drawing сетки

1) считать с файла точки и значения для треугольников
2) реализовать Mykeyboard()
3) реализовать MyDisplay()
4) засунуть всё в структуры
5)

## mydisplay

1) glrotate() from phi
2) glrorate() from teta
3) translate() by concrete vector

### additions

- [ ] додумать всё что было на паре, дописать требуемые вещи
- [ ] настроить документацию, разобраться с основными функциями, концепциями opengl programming
- [ ] algorithm woo implement


### todolist
- [ ] реализовать считывание с файла
- [ ] реализовать запись считанных данных в объекты типа struct Point struct Triangle 
- [ ] реализовать повороты 
- [ ] реализовать смещение объекта
- [ ] реализовать смещение камеры
- [ ] реализовать **zoom**
- [ ] 
### how it work
1) init a gl library
2) init a new window(size, position, display mode, name)
3) run a glutDisplayFunc() with our Display implementation
4) all of these run in infinity cycle glutMainLoop()

#### how work glutDisplayFunc()(truly our myDisplay func)
1) init a needed objects in function(for example our Triangles sets)
2) create them
3) render them

#### how we work with Triangles
1) glBegin(GL_TRIANGLES)
2) glVertex3d(Points)
3) glEnd()