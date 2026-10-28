# Псевдокод: GPA тооцоолуур

## Main
ЭХЛЭХ
  1. Хувьсагч зарлах:
       бүхэл тоо: n, i
       бутархай тоо: score, credit, points, totalPoints, totalCredit, gpa, max1, max2, max3
       текст: grade
  2. Эхний утга өгөх:
       totalPoints, totalCredit, max1, max2, max3 = 0
       grade = "", points = 0
  3. ДАВТАХ
        "Хичээлийн тоо (5-10): " гэж асууж n авна
     n < 5 OR n > 10 БАЙХ ХУГАЦААНД
  4. PrintHeader() дуудаж хүснэгтийн толгой хэвлэнэ
  5. i = 1
  6. i <= n БАЙХ ХУГАЦААНД ДАВТАХ
        6.1 ДАВТАХ
               "Оноо (0-100): " гэж асууж score авна
            score < 0 OR score > 100 БАЙХ ХУГАЦААНД
        6.2 ДАВТАХ
               "Кредит (1-6): " гэж асууж credit авна
            credit < 1 OR credit > 6 БАЙХ ХУГАЦААНД
        6.3 grade = GetGrade(score)
        6.4 points = GetPoints(score)
        6.5 totalPoints = totalPoints + points * credit
        6.6 totalCredit = totalCredit + credit
        6.7 Шилдэг 3-ыг шинэчлэх:
              ХЭРВЭЭ score > max1 БОЛ
                  max3 = max2; max2 = max1; max1 = score
              ҮГҮЙ ХЭРВЭЭ score > max2 БОЛ
                  max3 = max2; max2 = score
              ҮГҮЙ ХЭРВЭЭ score > max3 БОЛ
                  max3 = score
        6.8 i | score | grade | credit мөр хэвлэнэ
        6.9 i = i + 1
  7. gpa = totalPoints / totalCredit
  8. "Голч дүн: " ба gpa хэвлэнэ
  9. "Шилдэг 3 оноо: " max1, max2, max3 хэвлэнэ
ТӨГСӨХ

## Функц GetGrade(score) -> текст
  ХЭРВЭЭ score >= 90 БОЛ grade = "A"
  ҮГҮЙ ХЭРВЭЭ score >= 80 БОЛ grade = "B"
  ҮГҮЙ ХЭРВЭЭ score >= 70 БОЛ grade = "C"
  ҮГҮЙ ХЭРВЭЭ score >= 60 БОЛ grade = "D"
  ҮГҮЙ grade = "F"
  grade-ийг буцаана

## Функц GetPoints(score) -> бутархай
  ХЭРВЭЭ score >= 90 БОЛ points = 4.0
  ҮГҮЙ ХЭРВЭЭ score >= 80 БОЛ points = 3.0
  ҮГҮЙ ХЭРВЭЭ score >= 70 БОЛ points = 2.0
  ҮГҮЙ ХЭРВЭЭ score >= 60 БОЛ points = 1.0
  ҮГҮЙ points = 0
  points-ийг буцаана

## Функц PrintHeader()
  "Хичээл | Оноо | Үсэг | Кредит" гэж хэвлэнэ