#include<bits/stdc++.h>
using namespace std;
long long sum;
long long tot[200005];
int n;
char c[200005];
int pd(){
    for(int i=1,j=n;i<j;i++,j--){
        if(tot[i]!=tot[j]||c[i]!=c[j]){
            return 0;
        }
    }
    return 1;
}
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tot[i]>>c[i];
    }
    if(pd()){
        cout<<0;
        return 0;
    }
    else{
        for(int i=1,j=n;i<j;i++,j--){
            if(tot[i]==tot[j]&&c[i]!=c[j]){
                c[j]=c[i];
                sum+=tot[i];
            }
            else if(c[i]==c[j]){
                continue;
            }
            else{
                    int x=max(tot[i],tot[j]);
                    if(tot[i]>tot[j]){
                            int t=j;
                        while(x!=0&&t!=0){
                            if(c[t]==c[i]){
                                t--;
                                continue;
                            }
                            if(x<=tot[t]){
                                c[t]=c[i];
                                sum+=x;
                                break;
                            }
                            else{
                                x-=tot[t];
                                c[t]=c[i];
                                t--;
                                sum++;
                            }
                        }
                    }
                    else{
                        int t=j;
                    while(x!=0&&t!=0){
                        if(c[t]==c[j]){
                            t--;
                            continue;
                        }
                        if(x<=tot[t]){
                            c[t]=c[j];
                            sum+=x;
                            break;
                        }
                        else{
                            x-=tot[t];
                            c[t]=c[j];
                            t--;
                            sum++;
                        }
                    }
                    }

            }

        }
    }
    cout<<sum;
    return 0;
}
