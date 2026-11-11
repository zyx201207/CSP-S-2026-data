#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200000;
int n;
string str;
int ai;
char ci;
int hw(string str){
	int sum=0;
	for(int i=0,j=str.size()-1;j>=i;j--,i++){
		if(str[i]!=str[j]){
			//cerr<<"i="<<i<<",j="<<j<<"	"<<str[i]<<"!="<<str[j]<<endl;
			sum++;}
	}
	return sum;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ai>>ci;
		for(int j=1;j<=ai;j++){
			str+=ci;
		}
	}
//	for(int i=0;i<=str.size()-1;i++){
//		cerr<<i<<":";
//		cerr<<str[i]<<" ";
//	}
//	cerr<<endl;
	cout<<hw(str);
	return 0;
} 
