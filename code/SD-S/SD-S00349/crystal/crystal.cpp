#include<bits/stdc++.h>
#define lllld long long
#define endl '\n'
using namespace std;
long long a[500004];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lllld n,m;
	cin>>n>>m;
	bool speciA=1,speciB=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(speciA&&a[i]!=i){
			speciA=0;
		}
		if(speciB){
			if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
				speciB=0;
			}
		}
	}
	sort(a+1,a+n+1);
	if(speciA){
		lllld mym2=m;
		lllld i;
		for(i=1;i<=n;i++){
			if(mym2-i>=0){
				mym2-=i;
			}
			else break;
		}
		cout<<min(i,n);
		return 0;
	}
	if(speciB){
		long long mym2=m;
		lllld i;
		long long cccnt=0;
		for(int i=n-1;i>=0;i--){
			if(mym2-(a[n]-a[i])>=0){
				mym2-=(a[n]-a[i]);
				cccnt++;
			}
			else break;
		}
		cout<<min(cccnt+1,n);
		return 0;
	}
	
	lllld maxxx=0;
	for(int i=1;i<=n;i++){
		lllld anss=0,mym2=m;
		if(a[i]==a[i+1]){
			continue;
		}
		for(int j=i-1;j>=1&&m>=0;j--){
			if(mym2>=(a[i]-a[j])){
				anss++;
				mym2-=(a[i]-a[j]);
			}
			else break;
		}
		if(mym2>=0){
			maxxx=max(maxxx,min(anss,n));
		}
	
	}
	cout<<min(maxxx+1,n);
	return 0;
}
/*
//freopen feropen froopen fropen freeopen preopen luogu 1488910
*/
