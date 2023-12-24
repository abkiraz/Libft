# LIBFT

Merhaba 👋  
Burada libft projesi kazanımlarının önemli bir parçası olan
makefile dosyasının yazılışı hakkında bilgiler elde edeceksiniz.  
Ecole 42 libft projesinde sizden istenen bütün dosyaların tek bir klasörde olması olabilir  
Projeyi inceleyiniz ve Makefile dosyasını kendinize göre düzenleyiniz.  
Üniversitelerde veri yapıları dersinde istenen klasör hiyerarşisine uyumlu olacak şekilde hazırlanmış bir Makefile dosyası göreceksiniz.  
Yazılım hayatı boyunca gcc derleme ve Makefile dosyasını etkin kullanmak için aldığım bazı notları aşağıda bulabilirsiniz.

Klasör hiyerarşisi:  

- src klasörü -> Kaynak (.c) dosyalarınızın bulunduğu klasör
- lib klasörü -> Nesne (.o) dosyalarının bulunduğu klasör
- include Klasörü -> Başlık (.h) dosyalarınızın bulunduğu klasör
- doc Klasörü -> Raporunuzun bulunduğu klasör
- bin Klasörü -> Executable dosyalarınızın bulunduğu klasör
- readme.txt
- Makefile

## Makefile

### .c uzantısı (kaynak kod dosyaları)

`.c` uzantılı dosyalar, C/C++ programlama dillerinde yazılmış kaynak kod dosyalarıdır. Bu dosyalar, derleyici tarafından derlenerek, `.o` uzantılı ara dosyalara dönüştürülürler. Daha sonra, bu ara dosyalar birleştirilerek son uygulama oluşturulur.

### .o uzantısı (nesne dosyaları)

`.o` uzantılı dosyalar, C/C++ kaynak dosyalarının derlenmesi sonucu oluşan ara dosyalardır. Derleyici, her kaynak dosyası için bir `.o` dosyası oluşturur. Bu dosyalar, daha sonra birleştirilerek son uygulama oluşturulur. `.o` uzantılı dosyalar, makine koduna dönüştürülmüş bir kaynak dosyasını içerirler. Bu dosyalar, `.a` uzantılı kütüphaneler gibi, C/C++ kaynak dosyaları tarafından referans alınabilen bir işlev ve başlık kütüphanesi içerebilirler.

### .a uzantısı (statik kütüphane)

`.a` uzantılı dosyalar, C/C++ kaynak dosyaları tarafından referans alınabilen bir işlev ve başlık kütüphanesi içeren dosyalardır. Bu dosyalar, yalnızca birkaç işlevi depolayabilir veya 3D modelleme motoru gibi tüm bir işlev kütüphanesini içerebilir. Bu dosyalar genellikle GNU **ar** aracı tarafından oluşturulur. Statik kütüphaneler Unix benzeri sistemlerde daha yaygındırken, Windows sistemlerinde statik kütüphaneler genellikle `.lib` uzantısını kullanır. Statik kütüphanelerin kullanımı, dinamik kütüphanelere göre daha hızlı yükleme süreleri sağlasa da, daha büyük program dosyalarına neden olabilir.

**Derleme esnasında kullanılabilecek parametre ve işlevleri aşağıda verilmiştir:**
parametre | işlev
-|-
`ar` | statik kütüphane oluşturur  
`r` | kütüphane zaten varsa, eski dosyaları yeni dosyalarınızla değiştirir.
`c` | kütüphane henüz yoksa, kütüphaneyi oluştur
`s` | kütüphaneye bir nesne dosyası dizini yazarak veya mevcut bir dizini güncelleyerek kullanılır
`-g` | hata ayıklama amacıyla kullanılır. Bu seçenek derleyiciye, derlenen kodun hata ayıklama bilgilerini içeren bir dosya oluşturmasını söyler. Bu dosya, debug sırasında kullanılabilir
`-c` | derlenme sırasında, ara dosyaların oluşturulmasını sağlar. Bu seçenek, kaynak dosyalarını derleyerek, `.o` uzantılı ara dosyaları oluşturur.
`-I` | Derleyiciye, kaynak kodlarının (başlık dosyaları) bulunduğu *dizinleri* belirtir.
`-L` | Derleyiciye, kütüphanelerin (.a, .lib gibi) bulunduğu *dizinleri* belirtir.
`-l` | Derleyiciye, kullanılacak kütüphaneleri belirtir.
`-D` |  Derleyiciye, makro tanımları ekler.
