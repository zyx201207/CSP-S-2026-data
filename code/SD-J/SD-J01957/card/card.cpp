#include<bits/stdc++.h>
using namespace std;
const int N=5e5,M=3e5;
int n,m; 
int a[N+5],ans[M+5],flag[N+5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(m<=2){
		if(m==1){
			cout<<n;
		}
		else{
			if(a[n]==1){
				cout<<n<<" ";
				int answer=0;
				for(int i=1;i<=n;i++){
					if(a[i]!=1) answer++;
				}
				cout<<answer;
			}
			else{
				int answer=0;
				for(int i=1;i<=n;i++){
					if(a[i]!=2) answer++;
				}
				cout<<answer<<" ";	
				cout<<n;
			}
		}
		return 0;
	} 
	for(int i=1;i<=n;i++){
		stack<int> st;
		memset(flag,0,sizeof flag);
		for(int j=i;j<=n;j++){
			if(!flag[a[j]]){
				st.push(a[j]);
				flag[a[j]]=1;
			}
			else{
				while(st.top()!=a[j]){
					flag[st.top()]=0;
					st.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]=ans[j]+flag[j];
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
const int N=5e5,M=3e5;
int n,m; 
int a[N+5],ans[M+5],flag[N+5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(flag,0,sizeof flag);
		for(int j=n;j>=i;j--){
			for(int k=i;k<=j;k++){
				if(a[k]==a[j]){
					j=k;
					flag[a[k]]=1;
					break;
				}
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]=ans[j]+flag[j];
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
*/
