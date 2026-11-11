#include <fstream>
using namespace std;
int n;
string S;
ifstream fin("string.in");
ofstream fout("string.out");
int main() {
	fin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		fin>>a>>c;
		for(int j=0;j<a;j++){
			S+=c;
		}
	}
	long long ans=0;
	for(int i=0;i<S.length();i++){
		if(S[i]!=S[S.length()-1-i]) ans++;
	}
	fout<<ans/2<<endl;
}