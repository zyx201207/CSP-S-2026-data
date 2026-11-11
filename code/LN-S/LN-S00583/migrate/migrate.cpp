#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
vector<int> e[N];
int dist[N][N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int cnt=0;
        int a[n];
        bool key=1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]-a[i-1]>d){
                key=0;//压根就飞不到下一个岛 那就不可能有径 就不用判断了
            }
        }
        if(!key){
            cout<<key<<endl;
            return 0;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                    if(a[j]-a[i]<=d)continue;
                    if(a[j]-a[i]>2*d)break;//不会有距离更近的了
                if(a[j]-a[i]<=2*d and j!=i+1 and j==i+2){//如果两个岛的距离最多需要飞2次 且中间存在岛屿(j!=i+1)
                        dist[i][j]=2;
                        dist[j][i]=2;
                        //对于本题目特殊性质B 任何点之间的距离都是2 所以j需要等于i+2（中间只能有1个间隔岛）
                        cnt++;
                    }
            }

        cout<<cnt<<endl;
    }
    return 0;
    }
}
