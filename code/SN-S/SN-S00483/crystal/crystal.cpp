//SN-S00483 胡海瑧 西安市铁一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=5e5+5; 
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ch=a[2]-a[1],ff=0;
	for(int i=2;i<=n;i++){if((a[i]-a[i-1])!=ch) ff=1;}
	if(ff==0){
		int mm=(int)m/ch,c=1,cnt=0;
		while(mm>0){
			mm-=c;c+=1;
			if(mm<0) break;
			cnt++;
		}
		cout<<cnt+1;return 0;
	}
//	if(n<=5&&m<=10){
//		sort(a+1,a+n+1);
//		int suf[N]={0};
//		for(int i=2;i<=n;i++) suf[i]=a[i]-a[i-1];
//		
//	}
	return 0;
}
