#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
//#include <map>
using namespace std;
#define M 1000001
typedef long long ll;

int mapp[M],e,n,m,input[M];

struct Egde{
    int u,v,w;
}egde[2*M];

int find(int a)
{
    return mapp[a]==-1?a:mapp[a]=find(mapp[a]);
}


bool cmp(Egde a,Egde b)
{
    return a.w < b.w;
}
void wght(int u,int v,int w)
{
    egde[e].u = u;
    egde[e].v = v;
    egde[e].w = w;
    e++;
}
int kruscal()
{
    sort(egde,egde+e,cmp);
    int ans = 0;
    int cnt = 0;
    for(int i=0; i<e; i++)
    {
        int u = egde[i].u;
        int v = egde[i].v;
        int w = egde[i].w;
        int fu = find(u);
        int fv = find(v);
        if(fu != fv)
        {
            ans += w;
            mapp[fu] = fv;
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        e = 0;
        memset(mapp,-1,sizeof(mapp));
        scanf("%d %d",&n,&m);
        for(int i=0; i<n*m; i++)
        {
            scanf("%d",&input[i]);
        }
        for(int i=0; i<n*m; i++)
        {
            if(i%m != m-1)
                wght(i,i+1,abs(input[i]-input[i+1]));
            if(i/m != n-1)
                wght(i,i+m,abs(input[i]-input[i+m]));
        }
        printf("Case #%d:\n%d\n",cas,kruscal());
    }
return 0;
}
