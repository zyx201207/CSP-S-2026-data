#include<bits/stdc++.h>
int a[500007],p[500007];
std::set<int> table;
int st[500007],top=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	std::cin >> n >> m;
	int x;
	for(int i=1;i<=n;i++)std::cin >> a[i];
	for(int i=1;i<=n;i++){
		top=0;
		table.clear();
		for(int j=i;j<=n;j++){
			if(table.find(a[j])!=table.end()){
				top--;
				while(st[top]!=a[j])table.erase(table.find(st[top--]));
				top++;
			}
			else{
				st[top++]=a[j];
				table.insert(a[j]);
			}
		}
		for(int j=1;j<=m;j++)if(table.find(j)!=table.end())p[j]++;
		//std::cout << "debug";
		//for(int j=1;j<=m;j++)std::cout  << p[j];
		//std::cout << '\n';
	}
	for(int i=1;i<=m;i++)std::cout << p[i] << ' ';
	std::cout << '\n';
	return 0;
}
