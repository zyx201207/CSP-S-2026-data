#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	//^_^
    long long n,m,mid,cnt=0,ans=0,ans1=0,ans2=0,ans3=0,ans4=0,ans5=0,ans6=0,k;
    cin>>n>>m;
    k=m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	if(n%2==1){
		mid=(1+n)/2;//nÎªÆæÊı´ó´Õ 
		cnt=a[mid];
		for(int i=1;i<=n;i++){
			if((m-a[mid]+a[mid-i])>=0){
				m=m-a[mid]+a[mid-i];
				a[mid-i]=a[mid];
			}else break;
		}
		for(int i=1;i<=n;i++){
			if(cnt==a[i])ans++;
		}
		//mid×óÀ© 
		m=k;
		for(int i=1;i<=n;i++){
			a[i]=b[i];
		} 
		mid=(1+n)/2-1;
		cnt=a[mid];
		for(int i=1;i<=n;i++){
			if((m-a[mid]+a[mid-i])>=0){
				m=m-a[mid]+a[mid-i];
				a[mid-i]=a[mid];
			}else break;
		}
		for(int i=1;i<=n;i++){
			if(cnt==a[i])ans3++;
		}		
		//midÓÒÀ© 
		m=k;
		for(int i=1;i<=n;i++){
			a[i]=b[i];
		} 
		mid=(1+n)/2+1;
		cnt=a[mid];
		for(int i=1;i<=n;i++){
			if((m-a[mid]+a[mid-i])>=0){
				m=m-a[mid]+a[mid-i];
				a[mid-i]=a[mid];
			}else break;
		}
		for(int i=1;i<=n;i++){
			if(cnt==a[i])ans4++;
		}	   
		cout<<max(ans,max(ans3,ans4));		
	return 0;	
	}else{//nÎªÅ¼Êı´ó´Õ 
	    mid=(1+n)/2;//-
		cnt=a[mid];	
		for(int i=1;i<=n;i++){
			if((m-a[mid]+a[mid-i])>=0){
				m=m-a[mid]+a[mid-i];
				a[mid-i]=a[mid];
			}else break;
		}
	    for(int i=1;i<=n;i++){
		    if(cnt==a[i])ans1++;
		}
		//+
		for(int i=1;i<=n;i++){
			a[i]=b[i];
		}
	    mid=(1+n)/2+1;
		cnt=a[mid];	
		m=k;
		for(int i=1;i<=n;i++){
			if((m-a[mid]+a[mid-i])>=0){
				m=m-a[mid]+a[mid-i];
				a[mid-i]=a[mid];
			}else break;
		}
		for(int i=1;i<=n;i++){
			if(cnt==a[i])ans2++;
		}
	    //mid×óÀ© 	
		for(int i=1;i<=n;i++){
			a[i]=b[i];
		}
	    mid=(1+n)/2-1;
		cnt=a[mid];	
		m=k;
		for(int i=1;i<=n;i++){
			if((m-a[mid]+a[mid-i])>=0){
				m=m-a[mid]+a[mid-i];
				a[mid-i]=a[mid];
			}else break;
		}
		for(int i=1;i<=n;i++){
			if(cnt==a[i])ans5++;
		}	
		//midÓÒÀ©  
		for(int i=1;i<=n;i++){
			a[i]=b[i];
		}
	    mid=(1+n)/2+2;
		cnt=a[mid];	
		m=k;
		for(int i=1;i<=n;i++){
			if((m-a[mid]+a[mid-i])>=0){
				m=m-a[mid]+a[mid-i];
				a[mid-i]=a[mid];
			}else break;
		}
		for(int i=1;i<=n;i++){
			if(cnt==a[i])ans6++;
		}			
		cout<<max(ans6,max(ans5,max(ans2,ans1)));
	return 0;		
	}
	return 0;
}

