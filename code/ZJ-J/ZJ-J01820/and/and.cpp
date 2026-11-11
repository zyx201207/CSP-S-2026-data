#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
struct S{
	string shu;
} ejz[N];
string ass;
long long e[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	//10->2
	for(int i=1;i<=n;++i){
		int k=a[i];
		string t;
		while(k>0){
			if(k==1){
				t+='1';
				break;
			}else{
				t+='0'+k%2;
			}	
			k/=2;	
		}
		ejz[i].shu=t;
	}
	int mxl=ejz[1].shu.length();
	for(int i=2;i<=n;++i){
		int l=ejz[i].shu.length();
		int dt=mxl-l;
		ejz[i].shu+=dt*'0';
	}
	for(int i=mxl-1;i>=0;--i){
		int qwq=0;
		for(int j=1;j<=m;++j){
			if(ejz[j].shu[i]!='1'){
				qwq=1;
			}
		}
		if(qwq==0){
			ass+='1';
		}else{
			ass+='0';
		}
	}
	int ans=0;
	int al=ass.length();
	for(int i=al-1;i>=0;--i){
		if(ass[i]=='1'){
			ans+=e[al-1-i];
		}
	}
	cout << ans;
	return 0;
}
