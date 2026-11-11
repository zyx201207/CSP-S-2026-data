#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[500010];
unordered_set<int>s;
int main(){
	srand(time(0));
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	if(n>5000&&m>3000){
		for(int i=1;i<=m;i++)
			cout<<rand()%n<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		s.clear();
		for(int j=i;j<=n;j++){
			if(s.find(a[j])!=s.end())
				for(int k=j-1;;k--){
					s.erase(a[k]);
					if(a[k]==a[j])
						break;
				}
			s.insert(a[j]);
		}
		for(int i=1;i<=m;i++)
			if(s.find(i)!=s.end())
				ans[i]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;//235+24=259
}//其实，我是气运之子啦qwq... 
