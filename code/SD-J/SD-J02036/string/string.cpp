#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int ans;
string a;
int n,s;
char mn;
int tot;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int x=n;x>=1;x--){
		cin>>s;
		cin>>mn;
		for(int i=1;i<=s;i++){
			a[++tot]=mn;
		}
	}
	if(tot%2!=0){
	int l=(1+tot)/2;
	int r=(1+tot)/2;
	while(l>=1&&r<=tot){
		if(a[l]==a[r]){
			l--;
			r++;
		}else{
			ans++;
			l--;
			r++;
		}
	}
	}
	if(tot%2==0){
	int l=(1+tot)/2;
	int r=(1+tot+1)/2;
	while(l>=1&&r<=tot){
		if(a[l]==a[r]){
			l--;
			r++;
		}else{
			ans++;
			l--;
			r++;
		}
	}
	}
	cout<<ans;
	return 0;
}
