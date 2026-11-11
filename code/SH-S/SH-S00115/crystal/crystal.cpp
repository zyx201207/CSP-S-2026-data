#include<bits/stdc++.h>
using namespace std;
long long m,n,a[99999999],b[99999999],first,flag,count1,maxn,count2,k,count3,count4,flag1;
void solve(int x){
	for(int i=x-1;i>=1;i--){
		count2+=b[i];
		flag-=count2;
		if(flag<0){
			break;
		}else{
			count1+=1;
		}
	}
	if(count1>maxn){
		maxn=count1;
	}
	count1=0;
	count2=0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i-1]=a[i]-a[i-1];
	}
	if(n==1){
		cout<<n;
		return 0;
	}
	k=b[1];
	for(int i=1;i<n;i++){
	    if(b[i]!=k){
	    	flag1=1;
	    	break;
	    	
		}
	    else{
	    	if(count3<=m){
	    		count3+=k*i;
	    		count4++;
			}
		}
	}
	if(flag1==0){
		cout<<count4<<endl;
	}
	for(int i=2;i<=n;i++){
		flag=m;
		while(b[i]==0&&i<=n)i++;
		solve(i);
	}
	maxn+=1;
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
