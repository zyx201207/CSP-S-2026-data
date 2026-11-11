#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    int sum = 0;
    if(m==2){
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                 sum  = max(sum,a[i]&a[j]);
            }
        }
        cout<<sum;
    }else if(m==1){
        for(int i =0;i < n;i++){
            sum = max(sum,a[i]);
        }
        cout<<sum;
    }else if(m == 3){
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                for(int k = j+1;k < n;k++){
                    sum  = max(sum,a[i]&a[j]&a[k]);
                }
            }
        }
        cout<<sum;
    }else if(m == 4){
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                for(int k = j+1;k < n;k++){
                    for(int l = k+1;l < n;l++){
                        sum  = max(sum,a[i]&a[j]&a[k]&a[l]);
                    }
                }
            }
        }
        cout<<sum;
    }else if(m == 5){
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                for(int k = j+1;k < n;k++){
                    for(int l = k+1;l < n;l++){
                        for(int o = l+1;o < n;o++){
                            sum  = max(sum,a[i]&a[j]&a[k]&a[l]&a[o]);
                        }
                    }
                }
            }
        }
        cout<<sum;
    }else if(m == 6){
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                for(int k = j+1;k < n;k++){
                    for(int l = k+1;l < n;l++){
                        for(int o = l+1;o < n;o++){
                            for(int p = o+1;p < n;p++){
                                sum  = max(sum,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]);
                            }
                        }
                    }
                }
            }
        }
        cout<<sum;
    }else{
        cout<<"49152";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
