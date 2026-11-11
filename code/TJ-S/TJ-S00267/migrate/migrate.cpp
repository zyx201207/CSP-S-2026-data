#include<bits/stdc++.h>
using namespace std;
long long a[200001][3];
int z,y;
int mm(int i,int j){
    if(i>=z){
        return 0;
    }
    if(a[i][2]>j){
        a[i][2]=j;
        a[i][1]=1;
    }else if(a[i][2]==j){
        a[i][1]++;
    }
    for(int f=i+1;f<z;f++){
        if(llabs(a[f][0]-a[i][0])<=y){
            mm(f,j+1);
        }else{
            break;
        }
    }
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>z>>y;
        for(int j=0;j<z;j++){
            a[j][2]=z/y;
            if(z/y==2){
                a[j][2]=3;
            }
        }
        for(int j=0;j<z;j++){
            cin>>a[j][0];
        }
        mm(0,0);
        int cc=0;
        for(int j=0;j<z;j++){
            if(a[j][1]==2){
                cc++;
            }
        }
        cout<<cc<<endl;
        for(int j=0;j<z;j++){
            a[j][0]=0;
            a[j][1]=0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
