#include<bits/stdc++.h>
using namespace std;
long long a[30][2005],az[30],w[30];
int main(){
	freopen("string.in","t",stdin);
	freopen("string.out","w",stdout);
	int n;
	int x;
	char q;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>q;
		az[int(q)-96]++;
		a[int(q)-96][az[int(q)-96]]=x;
	}
	for(int i=1;i<=26;i++){
		int r=0,l=0;
		for(int j=1;j<=n;j++){
			if(r>=l){
				l+=a[i][j];
			}else{
				r+=a[i][j];
			}
			if(r>=l){
				w[i]=r-l;
			}else{
				w[i]=l-r;
			}
		}
	}
	sort(w+1,w+1+26);
	int x1=0;
	for(int i=26;i>=1;i--){
		if(x1<=w[i]){
			x1+=w[i];
		}else{
			x1-=w[i];
		}
	}
	long long sum,s[30];
	for(int i=1;i<=26;i++){
		for(int j=1;j<=n;j++){
			s[i]+=a[i][j];
			sum+=a[i][j];
		}
	}
	bool t;
	if(sum%2==0){
		for(int i=1;i<=26;i++){
			if(s[i]==sum/2){
				t=0;
			}else{
				t=1;
			}
		}	
	}else{
		cout<<x1/2;
	}
	if(t){
		cout<<(x1+1)/2;
	}else{
		cout<<x1/2;
	}
	return 0;
}
