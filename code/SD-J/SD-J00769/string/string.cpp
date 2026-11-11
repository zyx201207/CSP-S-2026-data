#include<iostream>
#include<cstring>
using namespace std;
const int maxn=200005;
int a[maxn];
char c[maxn];
string s="0";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0,num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ans+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(long long i=1;i<=ans/2;i++){
		if(s[i]!=s[ans-i+1]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
