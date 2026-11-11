#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct abc{
	char s;
	long long v;
}e[200005];
abc q[200005],q2[200005];
long long tp2,tp;
int main(){
	long long num=0,x;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>e[i].v>>e[i].s;
		num+=e[i].v;
	}
	x=num>>1;
	bool flag=0;
	for(long long i=1;i<=n;){
		if(x>=e[i].v){
			q[++tp2]=e[i];
			x-=e[i].v;
			i++;
		}
		else if(x!=0){
			q[++tp2].s=e[i].s;
			q[tp2].v=x;
			e[i].v-=x;
			x=0;
		}
		else if(x==0){
			if(!flag&&(num&1))e[i].v-=1;
			flag=1;
			q2[++tp]=e[i];
			i++;
		}
	}
	int st=1;
	while(tp){
		if(q[st].v>q2[tp].v){
			q[st].v-=q2[tp].v;
			if(q[st].s!=q2[tp].s){
				ans+=q2[tp].v;
			}
			tp--;
		}
		else if(q2[tp].v>q[st].v){
			q2[tp].v-=q[st].v;
			if(q[st].s!=q2[tp].s){
				ans+=q[st].v;
			}
			st++;
		}
		else{
			if(q[st].s!=q2[tp].s){
				ans+=q[st].v;
			}
			--tp;
			st++;
		}
	}
	cout<<ans;
	return 0;
} 
