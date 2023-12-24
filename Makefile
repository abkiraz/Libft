CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = libft.a

INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./lib
# $(INC_DIR) değişkeninde belirtilen dizindeki .h uzantılı dosyaların 
#listesini bulmak için wildcard işlevini kullanır.
INC_FILES = $(wildcard $(INC_DIR)/*.h)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
# patsubst, bir dizedeki belirli bir deseni başka bir desenle değiştirmek için kullanılır.
# % sembolü, $(SRC_DIR) ile başlayan ve .c ile biten herhangi bir dizeyi temsil eder.
# Bu ifade, $(SRC_FILES) listesindeki her bir .c dosyasının yolunu ve adını alır ve 
#bunları $(OBJ_DIR) ile başlayan ve .o ile biten bir dosya yoluna dönüştürür.
OBJ_FILES = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(NAME)

# değişken isimlerinin yanında : dan sonraki kısım bağımlılıkları ifade eder
# bunu anlamı sol taraftaki değişkenin oluşturulması sağ taraftaki değişkene bağlıdır
# burada o. uzantılı dosyalarını .a uzantılı bir dosyada arşivler
$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

# %.o ifadesinde joker karaketer % ile sadece bir .o uzantılı dosya hedeflenmiştir
# burada her .c uzantılı dosya için derleme işlemi gerçekleşir ve .o uzantılı dosyalar elde edilir
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
# @$(VARIABLE) ifadesinde @ işareti derleme işleminin terminalde çıktısını gizler
# $@ ifadesinde @ işareti kuralın ismi yerine geçer $(OBJ_DIR)/%.o gibi
# $< ifadesinde < işareti ilk bağımlılığın yerine geçer  $(SRC_DIR)/%.c gibi

# executable dosya oluşturma islemi
link: $(INC_FILES) $(NAME)
	$(CC) $(CFLAGS) -I $(INC_DIR) $(NAME) -o ./bin/program

# *.o ifadesinde joker karaketer * ile tüm .o uzantılı dosyalar hedeflenmiştir
# burada $(OBJ_DIR)/*.o yerine $(OBJ_FILES) yazılabilir
clean:
	$(RM) $(OBJ_DIR)/*.o

fclean: clean
	$(RM) $(NAME) ./bin/program

re: fclean all

.PHONY: all clean fclean re