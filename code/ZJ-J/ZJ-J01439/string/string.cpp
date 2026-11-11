#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct st{
	int a;
	char c;
};
st sti[N];
long long b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>sti[i].a>>sti[i].c;
		b[i]=b[i-1]+sti[i].a;
	}
	long long L=b[n];
	long long cnt=0,i=0,j=n,sy_a=sti[0].a,sy_b=sti[n].a,c_a=sti[0].c,c_b=sti[n].c;
	while(i<j){
		if(sy_a<=sy_b){
			if(c_a!=c_b){
				cnt+=sy_a;
			}
			i++;
			sy_b-=sy_a;
			sy_a=sti[i].a;
			c_a=sti[i].c;
		}
		else{
			if(c_a!=c_b){
				cnt+=sy_b;
			}
			j--;
			sy_a-=sy_b;
			sy_b=sti[j].a;
			c_b=sti[j].c;
		}
	}
	cout<<cnt;
}
