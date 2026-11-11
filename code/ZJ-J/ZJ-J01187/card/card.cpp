#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
bool f[300005],flag=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[i+1]) flag=0;
	}
	if(flag){
		for(int i=1;i<=n;i++)
			if(a[i]!=a[i+1]) 
			    cnt[a[i]]=i;
		for(int i=1;i<=m;i++){
		    if(i==m) printf("%d",cnt[i]);
		    else printf("%d ",cnt[i]);
	    }
		fclose(stdin);
	    fclose(stdout); 
	    return 0;
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		vector<int> st;
		for(int j=i;j<=n;j++){
		    if(!f[a[j]]){
		    	f[a[j]]=1;
		    	st.push_back(a[j]);
			}else{
				while(st.back()!=a[j]){
					int p=st.back();
					f[p]=0;
					st.pop_back();
				}
			}	
		}
		for(int i=0;i<st.size();i++)
			cnt[st[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(i==m) printf("%d",cnt[i]);
		else printf("%d ",cnt[i]);
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
