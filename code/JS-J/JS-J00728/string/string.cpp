#include<bits/stdc++.h>
using namespace std;
long long n;
const int N=2e5+5;
struct node{
	long long num;
	char s;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		cin>>a[i].s;
		sum+=a[i].num;
	}
	long long i=1;
	long long j=n;
	//cout<<a[j].num;
	long long ans=0;
	long long u=min(a[i].num,a[j].num),v=min(a[j].num,a[i].num);
	long long x=u,y=sum-v;
	
	while(x<=sum/2&&y>=sum/2){
		/*u=min(u,v);
		v=min(u,v);
		x+=u;
		y-=v;
		*/
		//cout<<u<<v;
		//cout<<x<<" "<<y<<endl;
		if(a[i].s!=a[j].s){
			ans+=min(u,v);
			
			//cout<<ans<<" ";
		}
		if(u==a[i].num){
			i++;
			u=min(a[i].num,sum/2);
			x+=u;
			}else{
			u=a[i].num-u;
			}
		if(v==a[j].num){
			j--;
			v=min(a[j].num,y-sum/2);
			y-=v;
			}else{
			v=a[i].num-v;
			}
		/*if(u>v){
				u-=v;
				j--;
				v=min(a[j].num,y-sum/2);
				y-=v;
			}else if(u<v){
				v-=u;
				i++;
				u=min(a[i].num,sum/2-x);
				x+=u;
			}else{
				i++;
				j--;
				v=min(a[j].num,y-sum/2);
				u=min(a[i].num,sum/2-x);
				x+=u;
				y-=v;
			}*/
		//
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
