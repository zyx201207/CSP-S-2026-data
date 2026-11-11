# include <bits/stdc++.h>
using namespace std;
int n,ans=1,k[500010];
long long s[500010],a[500010],m;
queue <int> q;
int main(){
	freopen("crystal.in","r",stdin);// 
	freopen("crystal.out","w",stdout);// 
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	k[1]=1;
	for (int i=2;i<=n;i++){
		s[i]=s[i-1]+(k[i-1])*(a[i]-a[i-1]);
		k[i]=k[i-1]+1;
		if (s[i]>m){
			while (!q.empty()){
				int p=q.front();q.pop();
				s[i]-=(a[i]-a[p]);k[i]--;
				if (s[i]<=m){break;}
			}
		}
		if (s[i]<=m){ans=max(ans,k[i]);}
		q.push(i);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
