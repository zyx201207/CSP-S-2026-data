#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll n,m,a[200005],s1[200005][35],s2[35],ss,s[35],s3[200005],ss1,s22[35];

void cf(int x){
	int y=a[x],xy=0,xxy=1;
	while(y>0){
		s1[x][xy]=y%2;
		s2[xxy]++;
		xy++;
		y/=2;
		xxy*=2;
	}
}

bool cmp(ll x,ll y){
	return x>y;
}

ll findx(ll x){
	for(int i=1;i<=ss1;i++){
		for(int j=1;j<=30;j++){
			if(s1[s3[i]][j]){
				s22[j]++;
			}
		}
	}
	ss1=0;
	s3[1]=0;
	for(int i=1;i<=1000000;i*=2){
		if(s22[i]>=m&&i!=x){
			s3[++ss1]=i;
		}
	}
	sort(s3+1,s3+ss1+1,cmp);
	return x+s3[1];
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		ll maxx=-1;
		for(int i=1;i<=n;i++){
			scanf("%ld",&a[i]);
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%ld",&a[i]);
		cf(i);
	}
	for(int i=1;i<=30;i++){
		if(s2[i]>=m){
			ss++;
			s[ss]=i;
		}
	}
	if(ss==1){
		cout<<s[ss];
		return 0;
	}
	if(ss==0){
		cout<<0;
		return 0;
	}
	sort(s+1,s+ss+1,cmp);
	for(int i=1;i<=n;i++){
		if(s1[i][s[1]]){
			s3[++ss1]=i;
		}
	}
	cout<<findx(s[1]);
	return 0;
}
