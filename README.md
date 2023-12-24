# LIBFT

Merhaba 👋  
Burada libft projesi kazanımlarının önemli bir parçası olan
makefile dosyasının yazılışı hakkında bilgiler elde edeceksiniz.  
Ecole 42 libft projesinde sizden istenen bütün dosyaların tek bir klasörde olması olabilir  
Projeyi inceleyiniz ve Makefile dosyasını kendinize göre düzenleyiniz.  
Üniversitelerde veri yapıları dersinde istenen klasör hiyerarşisine uyumlu olacak şekilde hazırlanmış bir Makefile dosyası göreceksiniz.  
Yazılım hayatımız boyunca kullanacağımız Makefile dosyasını etkin kullanmak için aldığım bazı notları aşağıda bulabilirsiniz.

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
`-O` |  parametresi gcc derleyicisinde optimizasyon seviyesini belirtmek için kullanılır.
 `-C` | seçeneği gcc derleyicisinde kod seviyesini belirtmek için kullanılır.

---

#### -C seçeneğiyle belirlenen kod seviyeleri şunlardır

- -C: Derleyici herhangi bir kısıtlama olmaksızın derler.
- -C0: En fazla optimizasyon sağlar ancak kodun anlaşılmasını zorlaştırır.
- -C1: Optimizasyonları sınırlar ve kodun anlaşılmasını kolaylaştırır.
- -C2: Daha az optimizasyon yapar, kodun anlaşılmasını daha da kolaylaştırır.
- -C3: En az optimizasyon yapılır, kodun anlaşılması en kolaydır.
- -CN: N numaralı C seviyesini belirtir, N değeri 0-3 arasında olmalıdır.

-C seçeneğiyle derleyiciye kodun ne kadar okunabilir/anlaşılabilir olması gerektiği söylenir. Düşük C seviyeleri kodun daha anlaşılır olmasını sağlar ancak performansı düşürür. Yüksek C seviyeleri ise performansı artırır fakat kodun okunmasını zorlaştırır.

Özetle, -C seçeneği gcc derleyicisinde kod seviyesi ve optimizasyon-okunabilirlik dengesini ayarlamaya yarar.

---

#### -O seçenekleri şunlardır

-O parametresi optimizasyon seviyesini belirler. Yani derlenen kodun çalışma performansını etkiler. Optimizasyon seviyesi arttıkça kodun çalışma hızı artar ancak okunabilirliği azalır.

- -O0: Hiçbir optimizasyon yapmaz, derleme hızı en yavaştır ama kod anlaşılması en kolaydır.
- -O1: Temel optimizasyonları etkinleştirir. Derleme hızı artar, kod biraz karışıklaşır.
- -O2: Daha gelişmiş optimizasyonları etkinleştirir. Derleme hızı daha da artar, kod daha da karışıklaşır.
- -O3: En üst seviye optimizasyonları etkinleştirir. Derleme hızı en yüksektir ancak kod anlaşılması zorlaşır.
- -Ofast: -O2 seçeneğine benzer ancak derleme hızını daha da artırmak için bazı geçerlilik kontrollerini atlar.
- -Os: Küçük boyutlu kod üretmeye odaklanır.

Bu seçeneklerle derleyici, kodu daha verimli çalışacak şekilde değiştirme, basitleştirme, kod parçalarını birleştirme gibi optimizasyonlar yapar. Böylece derlenen programın çalışma hızı artar. Ancak optimizasyon seviyesi arttıkça kodun anlaşılması zorlaşır.

---

#### `-O` ve `-C` parametreleri gcc derleyicisinde farklı işlevlere sahiptir

Dolayısıyla:

- -O parametresi kodun çalışma hızını (performansını),
- -C parametresi ise kodun okunabilirliğini/anlaşılabilirliğini belirler.

İkisi birlikte kullanıldığında hem kodun performansı hem de okunabilirliği/anlaşılabilirliği ayarlanabilir. Mesela -O2 -C1 derleyiciye hem yüksek optimizasyon hem de ortalama düzeyde okunabilirlik talimatı verir.

Özetle evet, -O ve -C farklı işlevlerdedir; biri performans diğeri okunabilirlik üzerinde etkilidir.
