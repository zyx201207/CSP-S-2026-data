#include<bits/stdc++.h>
using namespace std;
typedef long long bro;
bro n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;++i){
		cin>>a[i]>>c[i];
	}
	bro x = a[1],y = a[n];
	for(int i = 1,j = n;i < j;){
		if(c[i] == c[j]){
			bro xx = max(x-y,0ll);
			bro yy = max(y-x,0ll);
			if(xx == 0){
				i++;
				x = a[i];
			}if(yy == 0){
				j--;
				y = a[j];
			}
			if(xx != 0)x = xx;
			if(yy != 0)y = yy;
			//cout<<x<<' '<<y<<endl;
		}else{
			bro xx = max(x-y,0ll);
			bro yy = max(y-x,0ll);
			ans += min(x,y);
			if(xx == 0){
				i++;
				x = a[i];
			}if(yy == 0){
				j--;
				y = a[j];
			}
			if(xx != 0)x = xx;
			if(yy != 0)y = yy;
			//cout<<x<<'*'<<y<<endl;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}