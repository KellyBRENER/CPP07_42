/*
*********les templates***********
définir du code avec des variables de type,
utilisation de fonction et class template
int	max(int x, int y) {
return (x>=y ? x : y);
}
pour utiliser cette fonction avec n'importe quel type de variable, on utilise template.
pour cela, on annonce qu'on va utiliser un template et que son nom sera T:

template< typename T>
const T &	max(const T & x, const T & y) {
return (x>=y ? x : y);

pour utiliser ce cette fonction, il faut faire une instanciation du template:
soit explicite : max<int>(a, b); => préférable, pour un code plus clair
soit implicite : max(a, b);

on peut utiliser les templates pour créer des classes:
template<typename T>
class	List {
	private :
		T*	_content;
		List<T>*	next;
	public:
		List<T>(T const & content) {}
		List<T>( List<T> const & src) {}
		~List<T>(void) {}
}

utilisation :
int	main() {
	List<int>	a(42);
	List<float>	b(42.42);
	List<List<int>>	c(a);
}

on peut utiliser plusieurs template:
template<typename A, typename B>
instanciés comme suit:
List<int, float> ....
ou
List<int, int> ....
=> type id ou pas.

NB :  les définitions de template peuvent être mis dans
des fichiers.tpp

on peut définir des type par défaut:

template< typename T = float>
class Vertex {
	private:
	T const _x;
	T const _y;
	T const _z;
	Vertex() {}
	public :
		Vertex( T const & x, T const & y, T const & z) :
				_x(x), _y(y), _z(z) {}
		~Vertex() {}

		T const & getX() const {return this->_x;}
		T const & getY() const {return this->_y;}
		T const & getZ() const {return this->_z;}
}

template de surcharge de fonction:
template< typename T>
std::ostream &	operator<<(std::ostream & o, Vertex<T> const & v) {
	std::cout.precision(1);
	o << setiosflag(std::ios::fixed);
	o << "Vertex( ";
	o << v.getX() << ", ";
	o << v.getY() << ", ";
	o << v.getZ() << " )";
	return o;
}

pour instancier mon template avec le type par défaut j'utiliser la synthaxe :
vertex<>	a(12, 15, 68);
si je ne mets rien, le type est reconnu automatiquement,
si je mets <>, c'est le type par défaut qui est utilisé.
*/
