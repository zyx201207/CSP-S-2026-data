 #include<bits/stdc++.h>
 using namespace std;
 int a[500002],ans[300002],now[500002],s;
 int main(){
 	freopen("card.in","r",stdin);
 	freopen("card.out","w",stdout);
 	int n,m;
 	scanf("%d%d",&n,&m);
 	for(int i=1;i<=n;i++){
 		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		s=1;
		for(int d=i;d<=n;d++){
			now[s]=a[d];
			s++;
			for(int j=1;j<s-1;j++){
				if(a[d]==now[j])s=j+1;
			}
		}
		for(int j=1;j<s;j++){
			ans[now[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
 	return 0;
 }
