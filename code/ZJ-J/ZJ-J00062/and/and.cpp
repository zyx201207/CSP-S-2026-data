#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+100;

int n,m;
int a[MAXN],id[MAXN],snt=0,ans=0;
bool p[MAXN][40];

bool cmp(int a,int b){
	return a>b;
}

void to_two(int x,int k){
	int cnt=0;
	while(x!=0){
		if(x%2==1)p[k][cnt]=1;
		x/=2;
		cnt++;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		to_two(a[i],i);
	}
	if(m>2){
		for(int i=29;i>=0;i--){
			for(int j=1;j<=n;j++){
				if(p[j][i]==0||(j==2&&p[j][i]==0)) break;
				if(snt==m) break;
				else{
					if(id[j]==0) snt++;
					id[j]=1;
				}
			}
			if(snt==m) break;
		}
		for(int i=1;i<=n;i++){
			if(ans==0&&id[i]==1){
				ans+=a[i];
			}
			else if(id[i]==1){
				ans&=a[i];
			}
		}
		cout<<ans;
	}
	else if(m==1){
		cout<<a[1];
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
				if(ans!=0) break;
			}
			if(ans!=0) break;
		}
		cout<<ans;
	}
	return 0;
}
