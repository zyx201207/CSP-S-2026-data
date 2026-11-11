#include<iostream>
using namespace std;
int n;
struct nod{
	long long x;
	char c;
}a[200005];
long long cnt,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		cnt+=a[i].x;
	}
	cnt/=2;
	int r=n;
	for(int i=1;i<=n&&cnt>0;i++){
		if(a[i].x<=cnt){
			int f=a[i].x;
			while(f>=a[r].x){
				if(a[i].c!=a[r].c) sum+=a[r].x;
				cnt-=a[r].x;
				f-=a[r].x;
				r--;
			}
			if(f>0){
				cnt-=f;
				if(a[i].c!=a[r].c) sum+=f;
				a[r].x-=f;
			}
		}else{
			int f=cnt;
			while(f>=a[r].x){
				if(a[i].c!=a[r].c) sum+=a[r].x;
				cnt-=a[r].x;
				f-=a[r].x;
				r--;
			}
			if(f>0){
				cnt-=f;
				if(a[i].c!=a[r].c) sum+=f;
				a[r].x-=f;
			}	
		}
	}
	cout<<sum;
	return 0;
}
