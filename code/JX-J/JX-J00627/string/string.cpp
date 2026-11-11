#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    cin>>a;
    int cnt=0;
    int q[200005];
    string w[200005];
    for (int i=0;i<a;i++)
    {
        int c;
        string d;
        cin>>c>>d;
        cnt+=c;
        q[i]=c;
        w[i]=d;
    }
    cnt/=2;
    int o;
    o=a/2;
    int ant=0;
    for(int i=0;i<o;i++){
        int ax;
        ax=min(q[i],q[a-1-i]);
        if (w[i]!=w[a-1-i]){
            ant+=ax;
        }
        q[i]=q[i]-ax;
        q[a-1-i]=q[a-1-i]-ax;
        if(q[i]!=0){
            for(int j=a-1-i;j>i;j--){
                if(q[i]==0){
                    break;
                }
                ax=min(q[i],q[j]);
                if (w[i]!=w[j]){
                    ant+=ax;
                }
                q[i]=q[i]-ax;
                q[j]=q[j]-ax;

        }
        if(q[a-i-1]!=0){
            for(int j=i;j<o;j++){
                if(q[a-i-1]==0){
                    break;
                }
                ax=min(q[a-i-1],q[j]);
                if (w[a-i-1]!=w[j]){
                    ant+=ax;
                }
                q[a-i-1]=q[a-i-1]-ax;
                q[j]=q[j]-ax;

            }
        }
    }
    }
    cout<<ant;
    return 0;
    }
