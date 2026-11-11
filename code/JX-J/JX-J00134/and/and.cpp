#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],sum[40],f[N];
int book[N],pd[N][40];
struct sss{
	string n2;
	int id;
}b[N];
string zh(int x){
	int m=x;
	string s;
	while(m!=0){
		s=char(m%2+'0')+s;
		m/=2;
	}
	return s;
}

bool cmp(sss a,sss b){
	return a.n2>b.n2;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i].n2=zh(a[i]);
		b[i].id=i;
	}
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++){
		int ss=0;
		for(int j=0;j<int(b[i].n2.size());j++){
			ss++;
			if(b[i].n2[j]=='1'){
				sum[ss]++;
				pd[i][ss]=1;
			}
		}
	}
	int ma=b[1].n2.size()-1;
	while(ma!=0){
		if(sum[ma]>=m){
			for(int i=1;i<=n;i++){
				if(pd[i][ma]==0){
					book[i]=1;
					for(int j=1;j<=40;j++){
						if(pd[i][j]!=0){
							sum[j]--;
						}
					}
				}
			}
		}
		ma--;
	}
	int mm=0,i=0;
	while(mm<m){
		i++;
		if(book[i]==0){
			mm++;
			f[mm]=b[i].id;
		}	
	}
	int ans=a[f[1]];
	for(int i=2;i<=mm;i++){
		ans=ans&a[f[i]];
	}
	cout<<ans<<'\n';
    return 0;
}
