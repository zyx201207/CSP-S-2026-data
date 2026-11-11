#include <bits/stdc++.h> 
using namespace std;
long long a[1001000],book[1001000],b[1001000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,i,k,j,t;
	cin>>n>>m;
	for(i = 1;i <= n;i ++) cin>>a[i];
	for(i = 1;i <= n;i ++){
		t = i;
		for(j = 1;j <= n;j ++) book[a[j]] = 0;
		for(j = i;j <= n;j ++){
			if(book[a[j]] != 0){
				t = j;
			}
			book[a[j]] ++;
		}
		for(j = t;j <= n;j ++){
			b[a[j]] += 1;
		}
	}
	for(i = 1;i <= m;i ++){
		cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
}
