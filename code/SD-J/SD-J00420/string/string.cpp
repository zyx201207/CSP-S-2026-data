#include<bits/stdc++.h>
using namespace std;
//È¥×¢ÊÍ È¥×¢ÊÍ È¥×¢ÊÍ È¥×¢ÊÍ È¥×¢ÊÍ È¥×¢ÊÍ È¥×¢ÊÍ È¥×¢ÊÍ È¥×¢ÊÍ È¥×¢ÊÍ È¥×¢ÊÍ 
long long n,fr=1,to=0,cnt;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	to=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(fr>=to) break;
		if(c[fr]==c[to]){
			if(a[fr]>a[to]){
				a[fr]-=a[to];
				to--;
			}
			else if(a[fr]==a[to]){
				fr++;
				to--;
			}
			else{
				a[to]-=a[fr];
				fr++;
			}
		}
		else{
		if(a[fr]>a[to]){
			a[fr]-=a[to];
			cnt+=a[to];
			to--;
		}
		else if(a[fr]==a[to]){
			cnt+=a[fr];
			fr++;
			to--;
		}
		else{
			a[to]-=a[fr];
			cnt+=a[fr];
			fr++;
		}
		}
	}
	cout<<cnt;
	return 0;
}
