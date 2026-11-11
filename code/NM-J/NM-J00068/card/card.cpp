#include <bits/stdc++.h>
using namespace std;
int n,m,ans[300010],t[500010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		cin>>t[i];
	for(int h=1;h<=n;h++){
	
		vector<int> a;
		for(int i=h;i<=n;i++){
			a.push_back(t[i]);
			int loc=a.size();
			for(int j=0;j<a.size()-1;j++) 
			{
				if(a[j]==t[i]){
					loc=j;
					break;
				}
			}
			for(int j=loc;j<a.size()-1;){
				a.pop_back();
			}
		}
		for(int i=0;i<a.size();i++)
			ans[a[i]]++;
	//	cout<<endl;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
