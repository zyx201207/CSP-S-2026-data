#include <bits/stdc++.h>
using namespace std;
const int N=5e5+62,M=3e5+67;
int n,m,a[N],t[M]={0},c[M]={0};
stack <int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			t[a[j]]++;
			if(t[a[j]]>1){
				while(s.top()!=a[j]){
					t[s.top()]--;
					s.pop();
				}
				s.pop();
				t[a[j]]--;
			}
			s.push(a[j]);
		}
		while(!s.empty()){
			c[s.top()]++;
			t[s.top()]--;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",c[i]);
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
