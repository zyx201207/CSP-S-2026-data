#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct st{
	ll num;
	char word;
}a[200010];
ll n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].word;
	}
	int i=1,j=n;
	while(i<j){
		if(a[i].word!=a[j].word){
			ans+=min(a[i].num,a[j].num);
		}
		if(a[i].num-a[j].num==0){
			i++;j--;
		}else if(a[i].num-a[j].num>0){
			a[i].num=a[i].num-a[j].num;
			j--;
		}else{
			a[j].num=a[j].num-a[i].num;
			i++;
		}
	}
	cout<<ans;
	return 0;
} 
