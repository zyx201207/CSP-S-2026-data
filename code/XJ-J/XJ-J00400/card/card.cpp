#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			for(int k = i;k < j;k++){
				if(b[k] == a[j]){
					for(int l = k;l<=j;l++)
					{
						b[l]=0;
					}
				}
			}
			b[j]=a[j];
		}
		for(int l = 1;l <= n;l++)c[b[l]]++;
		for(int j = 1;j <= n;j++)b[j]=0;
	}
	for(int i = 1;i <= m;i++)cout << c[i] << " ";
	return 0;
}