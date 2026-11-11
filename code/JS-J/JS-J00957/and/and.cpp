#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<long long>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        if(n==1){
            cout<<a[1];
            return 0;
        }
        if(n==2){
            if(n==m){
                long long ans=a[1];
                for(int i=2;i<=n;i++)ans&=a[i];
                cout<<ans;
                return 0;
            }
            if(m==1){
                long long ans=-1;
                for(int i=1;i<=n;i++)ans=max(ans,a[i]);
                cout<<ans;
                return 0;
            }
        }
        if(n==3){
            if(m==1){
                long long ans=-1;
                for(int i=1;i<=n;i++)ans=max(ans,a[i]);
                cout<<ans;
                return 0;
            }
            if(n==m){
                long long ans=a[1];
                for(int i=2;i<=n;i++)ans&=a[i];
                cout<<ans;
                return 0;
            }
            else{
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++){
                        long long temp=a[i]&a[j];
                        ans=max(temp,ans);
                    }
                cout<<ans;
                return 0;
            }
        }
        if(n==4){
            if(m==1){
                long long ans=-1;
                for(int i=1;i<=n;i++)ans=max(ans,a[i]);
                cout<<ans;
                return 0;
            }
            if(m==2){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++){
                        long long temp=a[i]&a[j];
                        ans=max(temp,ans);
                    }
                cout<<ans;
                return 0;
            }
            if(m==3){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++){
                            long long temp=a[i]&a[j]&a[k];
                            ans=max(ans,temp);
                        }
                cout<<ans;
                return 0;
            }
            if(n==m){
                long long ans=a[1];
                for(int i=2;i<=n;i++)ans&=a[i];
                cout<<ans;
                return 0;
            }
        }
        if(n==5){
            if(m==1){
                long long ans=-1;
                for(int i=1;i<=n;i++)ans=max(ans,a[i]);
                cout<<ans;
                return 0;
            }
            if(m==2){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++){
                        long long temp=a[i]&a[j];
                        ans=max(temp,ans);
                    }
                cout<<ans;
                return 0;
            }
            if(m==3){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++){
                            long long temp=a[i]&a[j]&a[k];
                            ans=max(ans,temp);
                        }
                cout<<ans;
                return 0;
            }
            if(m==4){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;j<=n;k++)
                            for(int l=k+1;l<=n;l++){
                                long long temp=a[i]&a[j]&a[k]&a[l];
                                ans=max(ans,temp);
                            }
                cout<<ans;
                return 0;
            }
            if(n==m){
                long long ans=a[1];
                for(int i=2;i<=n;i++)ans&=a[i];
                cout<<ans;
                return 0;
            }
        }
        if(n==6){
            if(m==1){
                long long ans=-1;
                for(int i=1;i<=n;i++)ans=max(ans,a[i]);
                cout<<ans;
                return 0;
            }
            if(m==2){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++){
                        long long temp=a[i]&a[j];
                        ans=max(temp,ans);
                    }
                cout<<ans;
                return 0;
            }
            if(m==3){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++){
                            long long temp=a[i]&a[j]&a[k];
                            ans=max(ans,temp);
                        }
                cout<<ans;
                return 0;
            }
            if(m==4){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;j<=n;k++)
                            for(int l=k+1;l<=n;l++){
                                long long temp=a[i]&a[j]&a[k]&a[l];
                                ans=max(ans,temp);
                            }
                cout<<ans;
                return 0;
            }
            if(m==5){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++){
                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o];
                                    ans=max(ans,temp);
                                }
                cout<<ans;
                return 0;
            }
            if(n==m){
                long long ans=a[1];
                for(int i=2;i<=n;i++)ans&=a[i];
                cout<<ans;
                return 0;
            }
        }
        if(n==7){
            if(m==1){
                long long ans=-1;
                for(int i=1;i<=n;i++)ans=max(ans,a[i]);
                cout<<ans;
                return 0;
            }
            if(m==2){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++){
                        long long temp=a[i]&a[j];
                        ans=max(temp,ans);
                    }
                cout<<ans;
                return 0;
            }
            if(m==3){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++){
                            long long temp=a[i]&a[j]&a[k];
                            ans=max(ans,temp);
                        }
                cout<<ans;
                return 0;
            }
            if(m==4){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;j<=n;k++)
                            for(int l=k+1;l<=n;l++){
                                long long temp=a[i]&a[j]&a[k]&a[l];
                                ans=max(ans,temp);
                            }
                cout<<ans;
                return 0;
            }
            if(m==5){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++){
                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o];
                                    ans=max(ans,temp);
                                }
                cout<<ans;
                return 0;
            }
            if(m==6){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++){
                                        long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p];
                                        ans=max(ans,temp);
                                    }
                cout<<ans;
                return 0;
            }
            if(n==m){
                long long ans=a[1];
                for(int i=2;i<=n;i++)ans&=a[i];
                cout<<ans;
                return 0;
            }
        }
        if(n==8){
            if(m==1){
                long long ans=-1;
                for(int i=1;i<=n;i++)ans=max(ans,a[i]);
                cout<<ans;
                return 0;
            }
            if(m==2){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++){
                        long long temp=a[i]&a[j];
                        ans=max(temp,ans);
                    }
                cout<<ans;
                return 0;
            }
            if(m==3){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++){
                            long long temp=a[i]&a[j]&a[k];
                            ans=max(ans,temp);
                        }
                cout<<ans;
                return 0;
            }
            if(m==4){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;j<=n;k++)
                            for(int l=k+1;l<=n;l++){
                                long long temp=a[i]&a[j]&a[k]&a[l];
                                ans=max(ans,temp);
                            }
                cout<<ans;
                return 0;
            }
            if(m==5){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++){
                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o];
                                    ans=max(ans,temp);
                                }
                cout<<ans;
                return 0;
            }
            if(m==6){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++){
                                        long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p];
                                        ans=max(ans,temp);
                                    }
                cout<<ans;
                return 0;
            }
            if(m==7){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++){
                                            long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q];
                                            ans=max(ans,temp);
                                        }
                cout<<ans;
                return 0;
            }
            if(n==m){
                long long ans=a[1];
                for(int i=2;i<=n;i++)ans&=a[i];
                cout<<ans;
                return 0;
            }
        }
        if(n==9){
            if(m==1){
                long long ans=-1;
                for(int i=1;i<=n;i++)ans=max(ans,a[i]);
                cout<<ans;
                return 0;
            }
            if(m==2){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++){
                        long long temp=a[i]&a[j];
                        ans=max(temp,ans);
                    }
                cout<<ans;
                return 0;
            }
            if(m==3){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++){
                            long long temp=a[i]&a[j]&a[k];
                            ans=max(ans,temp);
                        }
                cout<<ans;
                return 0;
            }
            if(m==4){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;j<=n;k++)
                            for(int l=k+1;l<=n;l++){
                                long long temp=a[i]&a[j]&a[k]&a[l];
                                ans=max(ans,temp);
                            }
                cout<<ans;
                return 0;
            }
            if(m==5){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++){
                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o];
                                    ans=max(ans,temp);
                                }
                cout<<ans;
                return 0;
            }
            if(m==6){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++){
                                        long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p];
                                        ans=max(ans,temp);
                                    }
                cout<<ans;
                return 0;
            }
            if(m==7){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++){
                                            long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q];
                                            ans=max(ans,temp);
                                        }
                cout<<ans;
                return 0;
            }
            if(m==8){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++){
                                                long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r];
                                                ans=max(ans,temp);
                                            }
                cout<<ans;
                return 0;
            }
            if(n==m){
                long long ans=a[1];
                for(int i=2;i<=n;i++)ans&=a[i];
                cout<<ans;
                return 0;
            }
        }
        if(n==10){
            if(m==1){
                long long ans=-1;
                for(int i=1;i<=n;i++)ans=max(ans,a[i]);
                cout<<ans;
                return 0;
            }
            if(m==2){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++){
                        long long temp=a[i]&a[j];
                        ans=max(temp,ans);
                    }
                cout<<ans;
                return 0;
            }
            if(m==3){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++){
                            long long temp=a[i]&a[j]&a[k];
                            ans=max(ans,temp);
                        }
                cout<<ans;
                return 0;
            }
            if(m==4){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;j<=n;k++)
                            for(int l=k+1;l<=n;l++){
                                long long temp=a[i]&a[j]&a[k]&a[l];
                                ans=max(ans,temp);
                            }
                cout<<ans;
                return 0;
            }
            if(m==5){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++){
                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o];
                                    ans=max(ans,temp);
                                }
                cout<<ans;
                return 0;
            }
            if(m==6){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++){
                                        long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p];
                                        ans=max(ans,temp);
                                    }
                cout<<ans;
                return 0;
            }
            if(m==7){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++){
                                            long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q];
                                            ans=max(ans,temp);
                                        }
                cout<<ans;
                return 0;
            }
            if(m==8){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++){
                                                long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r];
                                                ans=max(ans,temp);
                                            }
                cout<<ans;
                return 0;
            }
            if(m==9){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++){
                                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s];
                                                    ans=max(ans,temp);
                                                }
                cout<<ans;
                return 0;
            }
            if(n==m){
                long long ans=a[1];
                for(int i=2;i<=n;i++)ans&=a[i];
                cout<<ans;
                return 0;
            }
        }
        if(n==11){
            if(m==1){
                long long ans=-1;
                for(int i=1;i<=n;i++)ans=max(ans,a[i]);
                cout<<ans;
                return 0;
            }
            if(m==2){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++){
                        long long temp=a[i]&a[j];
                        ans=max(temp,ans);
                    }
                cout<<ans;
                return 0;
            }
            if(m==3){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++){
                            long long temp=a[i]&a[j]&a[k];
                            ans=max(ans,temp);
                        }
                cout<<ans;
                return 0;
            }
            if(m==4){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;j<=n;k++)
                            for(int l=k+1;l<=n;l++){
                                long long temp=a[i]&a[j]&a[k]&a[l];
                                ans=max(ans,temp);
                            }
                cout<<ans;
                return 0;
            }
            if(m==5){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++){
                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o];
                                    ans=max(ans,temp);
                                }
                cout<<ans;
                return 0;
            }
            if(m==6){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++){
                                        long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p];
                                        ans=max(ans,temp);
                                    }
                cout<<ans;
                return 0;
            }
            if(m==7){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++){
                                            long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q];
                                            ans=max(ans,temp);
                                        }
                cout<<ans;
                return 0;
            }
            if(m==8){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++){
                                                long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r];
                                                ans=max(ans,temp);
                                            }
                cout<<ans;
                return 0;
            }
            if(m==9){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++){
                                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s];
                                                    ans=max(ans,temp);
                                                }
                cout<<ans;
                return 0;
            }
            if(m==10){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++)
                                                    for(int t=s+1;t<=n;t++){
                                                        long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t];
                                                        ans=max(ans,temp);
                                                    }
                cout<<ans;
                return 0;
            }
            if(n==m){
                long long ans=a[1];
                for(int i=2;i<=n;i++)ans&=a[i];
                cout<<ans;
                return 0;
            }
        }
        if(n==12){
            if(m==1){
                long long ans=-1;
                for(int i=1;i<=n;i++)ans=max(ans,a[i]);
                cout<<ans;
                return 0;
            }
            if(m==2){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++){
                        long long temp=a[i]&a[j];
                        ans=max(temp,ans);
                    }
                cout<<ans;
                return 0;
            }
            if(m==3){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++){
                            long long temp=a[i]&a[j]&a[k];
                            ans=max(ans,temp);
                        }
                cout<<ans;
                return 0;
            }
            if(m==4){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;j<=n;k++)
                            for(int l=k+1;l<=n;l++){
                                long long temp=a[i]&a[j]&a[k]&a[l];
                                ans=max(ans,temp);
                            }
                cout<<ans;
                return 0;
            }
            if(m==5){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++){
                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o];
                                    ans=max(ans,temp);
                                }
                cout<<ans;
                return 0;
            }
            if(m==6){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++){
                                        long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p];
                                        ans=max(ans,temp);
                                    }
                cout<<ans;
                return 0;
            }
            if(m==7){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++){
                                            long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q];
                                            ans=max(ans,temp);
                                        }
                cout<<ans;
                return 0;
            }
            if(m==8){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++){
                                                long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r];
                                                ans=max(ans,temp);
                                            }
                cout<<ans;
                return 0;
            }
            if(m==9){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++){
                                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s];
                                                    ans=max(ans,temp);
                                                }
                cout<<ans;
                return 0;
            }
            if(m==10){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++)
                                                    for(int t=s+1;t<=n;t++){
                                                        long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t];
                                                        ans=max(ans,temp);
                                                    }
                cout<<ans;
                return 0;
            }
            if(m==11){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++)
                                                    for(int t=s+1;t<=n;t++)
                                                        for(int u=t+1;u<=n;u++){
                                                            long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u];
                                                            ans=max(ans,temp);
                                                        }
                cout<<ans;
                return 0;
            }
            if(n==m){
                long long ans=a[1];
                for(int i=2;i<=n;i++)ans&=a[i];
                cout<<ans;
                return 0;
            }
        }
        if(n==13){
            if(m==1){
                long long ans=-1;
                for(int i=1;i<=n;i++)ans=max(ans,a[i]);
                cout<<ans;
                return 0;
            }
            if(m==2){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++){
                        long long temp=a[i]&a[j];
                        ans=max(temp,ans);
                    }
                cout<<ans;
                return 0;
            }
            if(m==3){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++){
                            long long temp=a[i]&a[j]&a[k];
                            ans=max(ans,temp);
                        }
                cout<<ans;
                return 0;
            }
            if(m==4){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;j<=n;k++)
                            for(int l=k+1;l<=n;l++){
                                long long temp=a[i]&a[j]&a[k]&a[l];
                                ans=max(ans,temp);
                            }
                cout<<ans;
                return 0;
            }
            if(m==5){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++){
                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o];
                                    ans=max(ans,temp);
                                }
                cout<<ans;
                return 0;
            }
            if(m==6){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++){
                                        long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p];
                                        ans=max(ans,temp);
                                    }
                cout<<ans;
                return 0;
            }
            if(m==7){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++){
                                            long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q];
                                            ans=max(ans,temp);
                                        }
                cout<<ans;
                return 0;
            }
            if(m==8){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++){
                                                long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r];
                                                ans=max(ans,temp);
                                            }
                cout<<ans;
                return 0;
            }
            if(m==9){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++){
                                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s];
                                                    ans=max(ans,temp);
                                                }
                cout<<ans;
                return 0;
            }
            if(m==10){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++)
                                                    for(int t=s+1;t<=n;t++){
                                                        long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t];
                                                        ans=max(ans,temp);
                                                    }
                cout<<ans;
                return 0;
            }
            if(m==11){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++)
                                                    for(int t=s+1;t<=n;t++)
                                                        for(int u=t+1;u<=n;u++){
                                                            long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u];
                                                            ans=max(ans,temp);
                                                        }
                cout<<ans;
                return 0;
            }
            if(m==12){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++)
                                                    for(int t=s+1;t<=n;t++)
                                                        for(int u=t+1;u<=n;u++)
                                                            for(int v=u+1;v<=n;v++){
                                                                long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v];
                                                                ans=max(ans,temp);
                                                            }
                cout<<ans;
                return 0;
            }
            if(n==m){
                long long ans=a[1];
                for(int i=2;i<=n;i++)ans&=a[i];
                cout<<ans;
                return 0;
            }
        }
        if(n==14){
            if(m==1){
                long long ans=-1;
                for(int i=1;i<=n;i++)ans=max(ans,a[i]);
                cout<<ans;
                return 0;
            }
            if(m==2){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++){
                        long long temp=a[i]&a[j];
                        ans=max(temp,ans);
                    }
                cout<<ans;
                return 0;
            }
            if(m==3){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++){
                            long long temp=a[i]&a[j]&a[k];
                            ans=max(ans,temp);
                        }
                cout<<ans;
                return 0;
            }
            if(m==4){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;j<=n;k++)
                            for(int l=k+1;l<=n;l++){
                                long long temp=a[i]&a[j]&a[k]&a[l];
                                ans=max(ans,temp);
                            }
                cout<<ans;
                return 0;
            }
            if(m==5){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++){
                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o];
                                    ans=max(ans,temp);
                                }
                cout<<ans;
                return 0;
            }
            if(m==6){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++){
                                        long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p];
                                        ans=max(ans,temp);
                                    }
                cout<<ans;
                return 0;
            }
            if(m==7){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++){
                                            long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q];
                                            ans=max(ans,temp);
                                        }
                cout<<ans;
                return 0;
            }
            if(m==8){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++){
                                                long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r];
                                                ans=max(ans,temp);
                                            }
                cout<<ans;
                return 0;
            }
            if(m==9){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++){
                                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s];
                                                    ans=max(ans,temp);
                                                }
                cout<<ans;
                return 0;
            }
            if(m==10){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++)
                                                    for(int t=s+1;t<=n;t++){
                                                        long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t];
                                                        ans=max(ans,temp);
                                                    }
                cout<<ans;
                return 0;
            }
            if(m==11){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++)
                                                    for(int t=s+1;t<=n;t++)
                                                        for(int u=t+1;u<=n;u++){
                                                            long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u];
                                                            ans=max(ans,temp);
                                                        }
                cout<<ans;
                return 0;
            }
            if(m==12){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++)
                                                    for(int t=s+1;t<=n;t++)
                                                        for(int u=t+1;u<=n;u++)
                                                            for(int v=u+1;v<=n;v++){
                                                                long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v];
                                                                ans=max(ans,temp);
                                                            }
                cout<<ans;
                return 0;
            }
            if(m==13){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++)
                                                    for(int t=s+1;t<=n;t++)
                                                        for(int u=t+1;u<=n;u++)
                                                            for(int v=u+1;v<=n;v++)
                                                                for(int w=v+1;w<=n;w++){
                                                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w];
                                                                    ans=max(ans,temp);
                                                                }
                cout<<ans;
                return 0;
            }
            if(n==m){
                long long ans=a[1];
                for(int i=2;i<=n;i++)ans&=a[i];
                cout<<ans;
                return 0;
            }
        }
        if(n==15){
            if(m==1){
                long long ans=-1;
                for(int i=1;i<=n;i++)ans=max(ans,a[i]);
                cout<<ans;
                return 0;
            }
            if(m==2){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++){
                        long long temp=a[i]&a[j];
                        ans=max(temp,ans);
                    }
                cout<<ans;
                return 0;
            }
            if(m==3){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++){
                            long long temp=a[i]&a[j]&a[k];
                            ans=max(ans,temp);
                        }
                cout<<ans;
                return 0;
            }
            if(m==4){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;j<=n;k++)
                            for(int l=k+1;l<=n;l++){
                                long long temp=a[i]&a[j]&a[k]&a[l];
                                ans=max(ans,temp);
                            }
                cout<<ans;
                return 0;
            }
            if(m==5){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++){
                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o];
                                    ans=max(ans,temp);
                                }
                cout<<ans;
                return 0;
            }
            if(m==6){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++){
                                        long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p];
                                        ans=max(ans,temp);
                                    }
                cout<<ans;
                return 0;
            }
            if(m==7){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++){
                                            long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q];
                                            ans=max(ans,temp);
                                        }
                cout<<ans;
                return 0;
            }
            if(m==8){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++){
                                                long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r];
                                                ans=max(ans,temp);
                                            }
                cout<<ans;
                return 0;
            }
            if(m==9){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++){
                                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s];
                                                    ans=max(ans,temp);
                                                }
                cout<<ans;
                return 0;
            }
            if(m==10){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++)
                                                    for(int t=s+1;t<=n;t++){
                                                        long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t];
                                                        ans=max(ans,temp);
                                                    }
                cout<<ans;
                return 0;
            }
            if(m==11){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++)
                                                    for(int t=s+1;t<=n;t++)
                                                        for(int u=t+1;u<=n;u++){
                                                            long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u];
                                                            ans=max(ans,temp);
                                                        }
                cout<<ans;
                return 0;
            }
            if(m==12){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++)
                                                    for(int t=s+1;t<=n;t++)
                                                        for(int u=t+1;u<=n;u++)
                                                            for(int v=u+1;v<=n;v++){
                                                                long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v];
                                                                ans=max(ans,temp);
                                                            }
                cout<<ans;
                return 0;
            }
            if(m==13){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++)
                                                    for(int t=s+1;t<=n;t++)
                                                        for(int u=t+1;u<=n;u++)
                                                            for(int v=u+1;v<=n;v++)
                                                                for(int w=v+1;w<=n;w++){
                                                                    long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w];
                                                                    ans=max(ans,temp);
                                                                }
                cout<<ans;
                return 0;
            }
            if(m==14){
                long long ans=-1;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        for(int k=j+1;k<=n;k++)
                            for(int l=k+1;l<=n;l++)
                                for(int o=l+1;o<=n;o++)
                                    for(int p=o+1;p<=n;p++)
                                        for(int q=p+1;q<=n;q++)
                                            for(int r=q+1;r<=n;r++)
                                                for(int s=r+1;s<=n;s++)
                                                    for(int t=s+1;t<=n;t++)
                                                        for(int u=t+1;u<=n;u++)
                                                            for(int v=u+1;v<=n;v++)
                                                                for(int w=v+1;w<=n;w++)
                                                                    for(int x=w+1;x<=n;x++){
                                                                        long long temp=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]&a[x];
                                                                        ans=max(ans,temp);
                                                                    }
                cout<<ans;
                return 0;
            }
            if(n==m){
                long long ans=a[1];
                for(int i=2;i<=n;i++)ans&=a[i];
                cout<<ans;
                return 0;
            }
        }
    }
    if(n<=10000){
        if(m==1){
            long long ans=-1;
            for(int i=1;i<=n;i++)ans=max(ans,a[i]);
            cout<<ans;
            return 0;
        }
        if(m==2){
            long long ans=-1;
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++){
                    long long temp=a[i]&a[j];
                    ans=max(temp,ans);
                }
            cout<<ans;
            return 0;
        }
        if(m==n){
            long long ans=a[1];
            for(int i=2;i<=n;i++)ans&=a[i];
            cout<<ans;
            return 0;
        }
    }
    return 0;
}
