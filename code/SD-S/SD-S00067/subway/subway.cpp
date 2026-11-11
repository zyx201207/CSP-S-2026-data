#ifndef _GLIBCXX_IOSTREAM
#define _GLIBCXX_IOSTREAM 1

#pragma GCC system_header

#include <bits/c++config.h>
#include <ostream>
#include <istream>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION
  extern istream cin;		
  extern ostream cout;		
  extern ostream cerr;		
  extern ostream clog;		

#ifdef _GLIBCXX_USE_WCHAR_T
  extern wistream wcin;		
  extern wostream wcout;	
  extern wostream wcerr;	
  extern wostream wclog;	
#endif
  static ios_base::Init __ioinit;

_GLIBCXX_END_NAMESPACE_VERSION
} 

#endif 

#ifndef _GLIBCXX_VECTOR
#define _GLIBCXX_VECTOR 1

#pragma GCC system_header

#include <bits/stl_algobase.h>
#include <bits/allocator.h>
#include <bits/stl_construct.h>
#include <bits/stl_uninitialized.h>
#include <bits/stl_vector.h>
#include <bits/stl_bvector.h> 
#include <bits/range_access.h>

#ifndef _GLIBCXX_EXPORT_TEMPLATE
# include <bits/vector.tcc>
#endif

#ifdef _GLIBCXX_DEBUG
# include <debug/vector>
#endif

#ifdef _GLIBCXX_PROFILE
# include <profile/vector>
#endif

#endif 

using namespace std;
int c,n,m,d,q;
int w[500010],k[110];
vector<int> a[110],t[110];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout<<"QWQ";
	int i=10000000;
	while(i--){
		cout<<"67";
	}
	return 0;
}























