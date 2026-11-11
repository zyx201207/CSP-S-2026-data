#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,top;
int a[500010],b[500010];
map<int,int> mp,mp2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	bool ok = 1;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		if(i > 1 && a[i - 1] > a[i])
			ok = 0;
	}
	if(ok){
		for(int i = 1;i <= m;i++)
			mp2[a[i]] = n;
		for(int i = 2;i <= n;i++){
			if(a[i] != a[i - 1]){
				mp2[a[i - 1]] -= (n - i + 1);
				if(a[i - 1] + 1 != a[i]){
					for(int j = a[i - 1];j <= a[i];j++)
						mp2[j] = 0;
				}
			}
		}
	}
	else{
		for(int j = 1;j <= n;j++){
			for(int i = j;i <= n;i++){
				if(mp[a[i]] == 1){
					while(b[top] != a[i]){
						mp[b[top]]--;
						top--;
					}
					mp[b[top]]--;
					top--;
				}
				mp[a[i]]++;
				b[++top] = a[i];
			}
			for(int i = 1;i <= top;i++)
				mp2[b[i]]++;
			top = 0;
			mp.clear();
		}
	}
	for(int i = 1;i <= m;i++)
		printf("%d ",mp2[i]);
	return 0;
}