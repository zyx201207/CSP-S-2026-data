#include<bits/stdc++.h>
using namespace std;
int n,m,p[20005],j;
string a[20005],s[20005],sum;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        while(p[i]>0){
            s[i]+=p[i]%2;
            p[i]/=2;
            j++;
        }
        while(j>0){
            a[i]+=p[j];
            j--;
        }
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;i<=n;i++){
                if(a[i]&a[j]-'0'>sum-'0'){
                    sum=max(a[i]&a[j],sum);
                    int q=i,w=j;
                }
            }
        }
        a[w]=0,a[q]=0;
        cout<<sum;
    }
    else{
            for(int i=1;i<=n;i++){
            for(int j=i+1;i<=n;i++){
                if(a[i]&a[j]>sum){
                    sum=max(int(a[i]&a[j]),int(sum));
                    int q=i,w=j;
                }
            }
        }

        f
        }
        string num=0;
        while(m--){
            m-=2;
            for(int j=1;i<=n;i++){
                if(sum&a[j]>num){
                    num=max(sum&a[j],num);
                    int q=i,w=j;
                }

        }
        a[w]=0,a[q]=0;

    }
    cout<<num;
    }

}
