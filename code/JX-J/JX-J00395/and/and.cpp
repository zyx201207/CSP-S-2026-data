#include<bits/stdc++.h>
using namespace std;
long long n,m,k[1000000],tail,ans=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    sort(k+0,k+n);
    ans=k[0];
    if(m==1){
    cout<<k[n-1];
    return 0;
    }
    if(m==2){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
			ans=k[i]&k[j];
            if(ans>=tail){
                tail=k[i]&k[j];
            }
        }
    }
    cout<<tail;
    return 0;
    }
    if(m==3){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
			for(int z=j+1;z<n;z++){
			    ans=k[i]&k[j]&k[z];
                if(ans>=tail){
                    tail=ans; 
                }
            }
        }
    }
    cout<<tail;
    return 0;
    }
    if(m==4){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
			for(int z=j+1;z<n;z++){
				for(int p=z+1;p<n;p++){
			        ans=k[i]&k[j]&k[z]&k[p];
                    if(ans>=tail){
                        tail=ans; 
                    }
                }
            }
        }
    }
    cout<<tail;
    return 0;
    }
    if(m==5){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
			for(int z=j+1;z<n;z++){
				for(int p=z+1;p<n;p++){
					for(int q=p+1;q<n;q++){
			            ans=k[i]&k[j]&k[z]&k[p]&k[q];
                        if(ans>=tail){
                            tail=ans; 
                        }
                    }
                }
            }
        }
    }
    cout<<tail;
    return 0;
    }
    if(m==6){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
			for(int z=j+1;z<n;z++){
				for(int p=z+1;p<n;p++){
					for(int q=p+1;q<n;q++){
						for(int a=q+1;a<n;a++){
			                ans=k[i]&k[j]&k[z]&k[p]&k[q]&k[a];
                            if(ans>=tail){
                                tail=ans; 
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<tail;
    return 0;
    }
    if(m==n){
        for(int i=1;i<n;i++){
            ans=ans&k[i];
        }
        cout<<ans;
    }
}
