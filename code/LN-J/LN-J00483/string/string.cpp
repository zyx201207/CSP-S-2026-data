#include<bits/stdc++.h>
using namespace std;
struct node{
    char aC;
    int aNum;
};
node a[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].aNum>>a[i].aC;
    int cur=n;
    long long tempI=a[1].aNum;
    long long cnt=0;
    int i=1;
    long long tempCur=a[cur].aNum;
    while(i<cur){
        if(a[cur].aC!=a[i].aC){
            cnt+=min(tempI,tempCur);
            //cout<<"cnt -> "<<cnt<<" tempI -> "<<tempI<<" tempCur -> "<<tempCur<<endl;
            int tempICopy=tempI;
            int tempCurCopy=tempCur;
            tempI-=min(tempICopy,tempCurCopy);
            tempCur-=min(tempICopy,tempCurCopy);
            //cout<<"tempCur -> "<<tempCur<<" min(tempI,tempCur) -> "<<min(tempI,tempCur)<<endl;
            if(tempCur==0){
                cur--;
                //cout<<"cur -> "<<cur<<endl;
                tempCur=a[cur].aNum;
            }
            if(tempI==0){
                i++;
                //cout<<"i -> "<<i<<endl;
                tempI=a[i].aNum;
            }
        }
        else{
            int tempICopy=tempI;
            int tempCurCopy=tempCur;
            tempI-=min(tempICopy,tempCurCopy);
            tempCur-=min(tempICopy,tempCurCopy);
            if(tempCur==0){
                cur--;
                //cout<<"cur -> "<<cur<<endl;
                tempCur=a[cur].aNum;
            }
            if(tempI==0){
                i++;
                //cout<<"i -> "<<i<<endl;
                tempI=a[i].aNum;
            }
        }
    }
    cout<<cnt;
    return 0;
}
//3000000000
