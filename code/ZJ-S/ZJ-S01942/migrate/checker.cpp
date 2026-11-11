#include <bits/stdc++.h>
using namespace std;
#define fre

namespace zyc{
	#define rep(i,l,r) for(int i=(l);i<=(r);i++)
	#define per(i,r,l) for(int i=(r);i>=(l);i--)
	#define pb push_back
	typedef long long ll;
	const int N=1e6+5;
	mt19937 rndd(time(0));
	ifstream fin;
	ofstream fout;
	string id;
	void copy(){
		string x="migrate"+id+".in";
		fin.open(x.c_str());
		fout.open("migrate.in");
		string s;
		while(getline(fin,s))fout<<s<<'\n';
		fin.close();
		fout.close();
	}
	int main(){
		id=" ";
		rep(i,1,9){
			id[0]='0'+i;
			getchar();
			copy();
			system("./migrate");
			string x="diff migrate.out migrate"+id+".ans -b -c";
			if(!system(x.c_str()))cout<<"AC on task "+id<<'\n';
		}
		return 0;
	}
}

int main(){
	
	zyc::main();
	return 0;
}
