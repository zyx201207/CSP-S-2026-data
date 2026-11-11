#include<bits/stdc++.h>
using namespace std;
const long long N=2*1e5+5;
long long n,m,ans=0;
struct date{
	long long x,y;
	char s;
}a[N];
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		a[i].x=a[i-1].y+1,a[i].y=a[i].x+m-1;
		cin>>c;
		a[i].s=c;
	}
	m=a[n].y;
	//for(int i=1;i<=n;i++) cout<<m-a[i].x+1<<' '<<m-a[i].y+1<<endl;
	int l=1,r=n;
	while(l<r){
		//printf("%d %d %c %d %d %c\n",a[l].y,m-a[r].x+1,a[l].s,a[l].x,m-a[r].y+1,a[r].s);
		if(a[l].s!=a[r].s){
			ans+=min(a[l].y,m-a[r].x+1)-max(a[l].x,m-a[r].y+1)+1;
			if(a[l].y>m-a[r].x+1) a[l].x=m-a[r].x+1;
			else a[r].y=m-a[l].y;
		}
		
		if(a[l].y>=m-a[r].x+1){
			r--;
		}
		else l++;
	}
	cout<<ans;
	return 0;
}
