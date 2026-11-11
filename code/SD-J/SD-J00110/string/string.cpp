#include<bits/stdc++.h>
#define int long long
using namespace std;
struct abc{
	int num;
	char s;
};
abc a[200050];
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	int b;
	char c;
	for(int i=1;i<=n;i++){
		cin>>b>>c;
		a[i].num=b;
		a[i].s=c;
	}
	abc l=a[1],r=a[n];
	int st=1,la=n,sum=0;
	while(st<=la){
		int mini=min(l.num,r.num);
		if(l.s!=r.s){
			sum+=mini;
		}
		l.num-=mini;
		r.num-=mini;
		if(l.num==0){
			st++;
			l=a[st];
		}
		if(r.num==0){
			la--;
			r=a[la];
		}
	}
	cout<<sum;
	return 0;
}

