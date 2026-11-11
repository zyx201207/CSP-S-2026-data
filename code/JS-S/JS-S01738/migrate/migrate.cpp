#include <bits/stdc++.h>
using namespace std;
const int N=5005;
//priority_queue
//bool operator <(const qwe&)const{}
struct nu{
    int a[20];
    bool t;//true-> + false-> -
    nu(){
        memset(a,0,sizeof(a));
    }
}num[N];
int inf;
int id,T,n,a[N],dist[N][3];
int d[20];
void _cin(int i){
    string s;
    cin>>s;
    bool k=true;
    if(s[0]=='-'){
        k=false;
    }
    int j=19;
    //cout<<s<<'\n';
    for(int ii=(k?0:1);ii<s.size();ii++,j--)num[i].a[j]=s[ii]-'0';
    //for(int ii=0;ii<=19;ii++)cout<<num[i].a[ii];
    //cout<<'\n';
    num[i].t=k;
}
bool temp(int z[]){
    for(int ii=0;ii<=19;ii++){
        if(z[ii]!=d[ii]){
            return z[ii]<=d[ii];
        }
    }
    return true;
}
bool absjian(int i,int j){
    int z[20];
    memset(z,0,sizeof(z));
    if(num[i].t==num[i].t){//-
        if(num[i].t){
        int p=0;
        for(int ii=19;ii>=0;ii--){//i>j
                //cout<<ii<<' '<<num[i].a[ii]<<' '<<num[j].a[ii]<<'\n';
            p=num[i].a[ii]-num[j].a[ii]-p;
            if(p<0){z[ii]=p+10;p=1;}
            else{z[ii]=p;p=0;}
        }
        //cout<<z[18]<<z[19]<<'\n';
        return temp(z);}
        else{
        int p=0;
        for(int ii=19;ii>=0;ii--){//i>j
                //cout<<ii<<' '<<num[i].a[ii]<<' '<<num[j].a[ii]<<'\n';
            p=num[j].a[ii]-num[i].a[ii]-p;
            if(p<0){z[ii]=p+10;p=1;}
            else{z[ii]=p;p=0;}
        }
        //cout<<z[18]<<z[19]<<'\n';
        return temp(z);


        }
    }
    else{//+
        int p=0;
        for(int ii=19;ii>=0;ii--){//i>j
            p=num[i].a[ii]+num[j].a[ii]+p;
            z[ii]=p%10;
            p=p/10;
        }
        return temp(z);
    }
}
void updata(int i,int j){/*
    for(int ii=0;ii<=2;ii++)cout<<dist[i][ii]<<' ';
            cout<<'\n';
    for(int ii=0;ii<=2;ii++)cout<<dist[j][ii]<<' ';
            cout<<'\n';*/
    int z=0,x=0;
    int s[3];
    for(int k=0;k<3;k++){
        if(dist[i][z]<=dist[j][x]+1){
            s[k]=min(dist[i][z],dist[j][x]+1);
            z++;
        }else{
            s[k]=min(dist[i][z],dist[j][x]+1);
            x++;
        }
    }
    for(int ii=0;ii<3;ii++)dist[i][ii]=s[ii];
    /*
    for(int ii=0;ii<=2;ii++)cout<<dist[i][ii]<<' ';
            cout<<'\n';
    for(int ii=0;ii<=2;ii++)cout<<dist[j][ii]<<' ';
            cout<<'\n';*/
}
bool check(int i){
    int z=dist[i][0];
    int x=dist[i][1];
    int c=dist[i][2];
    return (z==x&&z!=inf&&c!=z);
}
int f[20];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dist,0x3f,sizeof(dist));
    inf=dist[0][0];
    cin>>id>>T;
    while(T--){
        cin>>n;
        string d1;
        cin>>d1;
        for(int i=19;i>=0&&i>=20-d1.size();i--)d[i]=d1[19-i]-'0';
        //for(int i=0;i<=19;i++)cout<<d[i];
        //cout<<'\n';


        for(int i=1;i<=n;i++)_cin(i);
        //cout<<absjian(4,1)<<'\n';
        //cout<<absjian(2,1)<<'\n';
        dist[1][0]=0;

        int sum1=0;
        for(int i=2;i<=n;i++){
            int j=i-1;
            while(absjian(i,j)&&j>=1){
                updata(i,j);
                //cout<<j<<'\n';
                j--;
            }
            //for(int ii=0;ii<=2;ii++)cout<<dist[i][ii]<<' ';
            //cout<<'\n';
            if(check(i))sum1++;
        }

        cout<<sum1<<'\n';
    }





    return 0;
}
