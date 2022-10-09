// Snakes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/OpenGL.hpp>
#include<sstream>
using namespace sf;
#define MAXPOSX 600
#define MAXPOSY 600
#define NUMFOOD 10

std::string IntToString(int num)
{
    std::stringstream string_object_name;

    // insert operation

    string_object_name << num;

    // extract operation

    return string_object_name.str();
}

float GetRandomFloatBetween0and1()
{
    return ((float)(rand() % 255)) / 254.0f;
}
struct FoodVec;

class Batcher
{
    VertexArray varray;
public:
    void Clear() { varray.clear(); }
    void SetPrimitiveType(PrimitiveType type) { varray.setPrimitiveType(type); }
    void AddPoint(Vector2f pos, Color color) 
    {
        varray.append(Vertex(pos,color));
    }

    
    void AddDigit(char num,Vector2f pos, float scale, Color color) 
    {
        
        switch (num)
        {
        case '0':
            varray.append(Vertex(Vector2f(-0.4f,0.7f)*scale+pos, color));
            varray.append(Vertex(Vector2f(-0.4f, -0.7f) * scale + pos, color));

            varray.append(Vertex(Vector2f(0.4f, 0.7f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, -0.7f) * scale + pos, color));

            varray.append(Vertex(Vector2f(-0.4f, 0.7f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.0f, 0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(0.4f, 0.7f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.0f, 0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(-0.4f, -0.7f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.0f, -0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(0.4f, -0.7f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.0f, -0.85f) * scale + pos, color));

            
            break;
        case '1':
            varray.append(Vertex(Vector2f(0.0f, -0.85f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.0f, 0.85f) * scale + pos, color));

            break;
        case '2':
            varray.append(Vertex(Vector2f(-0.4f, -0.85f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, -0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(-0.4f, 0.85f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, 0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(-0.4f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, 0.0f) * scale + pos, color));

            varray.append(Vertex(Vector2f(-0.4f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(-0.4f, 0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(0.4f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, -0.85f) * scale + pos, color));

            break;
        case '3':
            varray.append(Vertex(Vector2f(0.4f, -0.85f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, 0.85f) * scale + pos, color));
            
            varray.append(Vertex(Vector2f(-0.4f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, 0.0f) * scale + pos, color));

            varray.append(Vertex(Vector2f(-0.4f, 0.85f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, 0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(-0.4f, -0.85f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, -0.85f) * scale + pos, color));
            break;
        case '4':
            varray.append(Vertex(Vector2f(-0.4f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(-0.4f, -0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(0.4f, -0.85f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, 0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(-0.4f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, 0.0f) * scale + pos, color));
            break;
        case '5':
            varray.append(Vertex(Vector2f(-0.4f, -0.85f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, -0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(-0.4f, 0.85f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, 0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(-0.4f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, 0.0f) * scale + pos, color));

            varray.append(Vertex(Vector2f(-0.4f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(-0.4f, -0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(0.4f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, 0.85f) * scale + pos, color));
            break;
        case '6':
            varray.append(Vertex(Vector2f(0.4f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, 0.85f) * scale + pos, color));
            
            varray.append(Vertex(Vector2f(-0.4f, 0.85f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, 0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(-0.4f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, 0.0f) * scale + pos, color));

            
            varray.append(Vertex(Vector2f(-0.4f, -0.85f) * scale + pos, color));
            varray.append(Vertex(Vector2f(-0.4f, 0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(0.4f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, 0.85f) * scale + pos, color));

            break;
        case '7':
            varray.append(Vertex(Vector2f(0.4f, -0.85f) * scale + pos, color));
            varray.append(Vertex(Vector2f(-0.4f, 0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(-0.4f, -0.85f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, -0.85f) * scale + pos, color));

            break;
        case '8':
            varray.append(Vertex(Vector2f(0.0f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(-0.4f, -0.425f) * scale + pos, color));

            varray.append(Vertex(Vector2f(-0.4f, -0.425f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.0f, -0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(0.0f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, -0.425f) * scale + pos, color));

            varray.append(Vertex(Vector2f(0.4f, -0.425f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.0f, -0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(0.0f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(-0.4f, 0.425f) * scale + pos, color));

            varray.append(Vertex(Vector2f(-0.4f, 0.425f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.0f, 0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(0.0f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, 0.425f) * scale + pos, color));

            varray.append(Vertex(Vector2f(0.4f, 0.425f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.0f, 0.85f) * scale + pos, color));

            break;
        case '9':
            varray.append(Vertex(Vector2f(-0.4f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(-0.4f, -0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(0.4f, -0.85f) * scale + pos, color));
            varray.append(Vertex(Vector2f(-0.4f, -0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(0.4f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(-0.4f, 0.0f) * scale + pos, color));


            varray.append(Vertex(Vector2f(0.4f, -0.85f) * scale + pos, color));
            varray.append(Vertex(Vector2f(0.4f, 0.85f) * scale + pos, color));

            varray.append(Vertex(Vector2f(-0.4f, 0.0f) * scale + pos, color));
            varray.append(Vertex(Vector2f(-0.4f, -0.85f) * scale + pos, color));
            break;
        default:
            std::cout << num;
        }

    }

    void AddNumber(std::string number,Vector2f pos,float scale, Color color)
    {
        Vector2f offset = {0.0f,0.0f};
        for (auto& c : number) 
        {
            AddDigit(c,pos+offset,scale,color);
            offset += {scale+0.01f*scale, 0};
        }
    }
   
    
    void AddForwardArrow(Vector2f pos, float scale, Color color) 
    {

        varray.append(Vertex(Vector2f(-0.5f, 0.0f) * scale + pos, color));
        varray.append(Vertex(Vector2f(0.5f, 0.0f) * scale + pos, color));
 
        varray.append(Vertex(Vector2f(0.3f, 0.2f) * scale + pos, color));
        varray.append(Vertex(Vector2f(0.5f, 0.0f) * scale + pos, color));

        varray.append(Vertex(Vector2f(0.3f, -0.2f) * scale + pos, color));
        varray.append(Vertex(Vector2f(0.5f, 0.0f) * scale + pos, color));

    }

    void AddRestartArrow(Vector2f pos, float scale, Color color) 
    {
        varray.append(Vertex(Vector2f(-0.5, 0.0f) * scale + pos, color));
        varray.append(Vertex(Vector2f(-0.5f, 0.5f) * scale + pos, color));

        varray.append(Vertex(Vector2f(-0.5f, 0.5f) * scale + pos, color));
        varray.append(Vertex(Vector2f(0.5f, 0.5f) * scale + pos, color));

        varray.append(Vertex(Vector2f(0.5f, 0.5f) * scale + pos, color));
        varray.append(Vertex(Vector2f(0.5f, -0.5f) * scale + pos, color));

        varray.append(Vertex(Vector2f(0.5f, -0.5f) * scale + pos, color));
        varray.append(Vertex(Vector2f(0.0f, -0.5f) * scale + pos, color));

        varray.append(Vertex(Vector2f(0.1f, -0.6f) * scale + pos, color));
        varray.append(Vertex(Vector2f(0.0f, -0.5f) * scale + pos, color));
        
        varray.append(Vertex(Vector2f(0.0f, -0.5f) * scale + pos, color));
        varray.append(Vertex(Vector2f(0.0f, -0.4f) * scale + pos, color));

    }

  
    void Draw(RenderTarget& target, RenderStates states) { target.draw(varray, states); };

};

struct Food
{
    Vector2f position;
    const static float minSize;
    const static float maxSize;
    float amount;//between 0 and 1
    const static Color color;
    Food()
    {
        position = { GetRandomFloatBetween0and1() * MAXPOSX,GetRandomFloatBetween0and1() * MAXPOSY };
        amount = GetRandomFloatBetween0and1();
    }
    float GetSize()
    {
        return (minSize + (maxSize - minSize) * amount);
    }
    void Draw(Batcher& batcher)
    {
        float fac = GetSize();
        batcher.AddPoint(position + Vector2f{ 0.5f, 0.5f }*fac, color);
        batcher.AddPoint(position + Vector2f{ -0.5f, -0.5f }*fac, color);
        batcher.AddPoint(position + Vector2f{ -0.5f, 0.5f }*fac, color);
        batcher.AddPoint(position + Vector2f{ 0.5f, -0.5f }*fac, color);

    }
};
const Color Food::color = Color(240, 160, 100);
const float Food::minSize = 1.5f;
const float Food::maxSize = 10.0f;
struct FoodVec
{
    std::vector<Food> food;
    void AddFood(int i = 1) { for (auto x = 0; x < i; x++) { food.push_back(Food()); } }
    bool changed = false;
    void Draw(Batcher& batcher)
    {
        for (auto& fd : food) { fd.Draw(batcher); }
    }
};

class Snake 
{
protected:
    float drag;
    std::vector<Vector2f> points;
    Vector2f vel;
    Color color;
    float idealDistance;
    float speed;
public:
    void AddPoint() 
    {
        auto nPoints = points.size();
        if (nPoints>1)
        {
            points.push_back(points[nPoints - 1] -points[nPoints-2]+ points[nPoints - 1]);
        }
        else 
        {
            points.push_back(points[0]-vel);
        }
    }
    void ForcePosition(Vector2f pos) { points[0] = pos; }
    Vector2f GetHeadPosition() { return points[0]; }
    Snake() 
    {
        speed = 70.0f;
        color = Color::Red;
        idealDistance = 5.0f;
        points.push_back({10.0f+GetRandomFloatBetween0and1()*(MAXPOSX-10.0f),10.0f + GetRandomFloatBetween0and1() * (MAXPOSY-10.0f)});
        AddPoint();
    }
    void IncreaseSpeed(float fac)
    {
        speed *= fac;
    }
protected: 
    virtual Vector2f GetDirection(FoodVec& vec) = 0;
public:

    void Update(float delta,FoodVec& vec) 
    {
        Vector2f acc = GetDirection(vec)*speed - vel*drag;
        vel += acc * delta;
        points[0]+=vel*delta;
        //this sucks
        for (int i = 1;i<points.size(); i++) 
        {
            auto dist=points[i] - points[i - 1];
            auto dist1 = dist.x * dist.x + dist.y * dist.y;
            dist1 = sqrt(dist1);
            if (dist1>idealDistance)
            {
                points[i] = points[i - 1] + dist * idealDistance / dist1;

            }
            
        }
    };
    void Draw(Batcher& batcher) 
    {
        for (int i = 1; i < points.size(); i++)
        {
            batcher.AddPoint(points[i], color);
            batcher.AddPoint(points[i-1], color);

        }

    }
};
class PlayerSnake:public Snake 
{
public:
    PlayerSnake(){
        color = Color(80, 250, 100);
        drag = 1.8f;
        speed = 120.0f;
    }
    Vector2f GetDirection(FoodVec& vec)
    {
        Vector2f dir = Vector2f{(float)(Keyboard::isKeyPressed(Keyboard::Right)- Keyboard::isKeyPressed(Keyboard::Left) ),(float)(Keyboard::isKeyPressed(Keyboard::Down) - Keyboard::isKeyPressed(Keyboard::Up)) };
        return dir;
    }
    
};

class AISnake :public Snake
{
protected:
    Vector2f dir;
    Vector2f target;
    Vector2f GetNearestPos(FoodVec& vec) 
    {
        Vector2f nearestSoFar = { 50000.0,50000.0 };
        auto pos = GetHeadPosition();
        auto prevDist = INFINITY;
        for (size_t i = 0; i < vec.food.size(); i++)
        {
            Vector2f thisPos = vec.food[i].position;
            auto newDist = pow(pos.x - thisPos.x, 2.0f) + pow(pos.y - thisPos.y, 2.0f);
            if (newDist<prevDist)
            {
                prevDist = newDist;
                nearestSoFar = thisPos;
            }
        }
        return nearestSoFar;
    }
public:
    AISnake(FoodVec& vec) 
    {
        drag = 0.75f;
        dir = { 1.0f,0.0f };
        if (!vec.food.size())
        {
            Transform trans;
            trans.rotate(0.1f);

            target = GetHeadPosition() + trans.transformPoint(dir);
        }
        else {
            target = GetNearestPos(vec);
        }
        speed = 30.0f;
        color = Color(150,120,230);
    }
    Vector2f GetDirection(FoodVec& vec)
    {

        if (!vec.food.size())
        {
            Transform trans;
            trans.rotate(0.01f);
            dir = trans.transformPoint(dir);
            target = GetHeadPosition() + dir;
        }
        else 
        {
            if (vec.changed)
            {
                target = GetNearestPos(vec);

            }
        }
        auto headPos = GetHeadPosition();
        auto dir= target - headPos;
        auto dist = dir.x * dir.x + dir.y * dir.y;
        return dir/sqrt(dist);
    }

};


class State
{
protected:
    RenderWindow* window;
    
public:
    State(RenderWindow* _window) :window(_window) {}
    virtual State* OnMainLoop() = 0;
};

class LooseState :public State 
{
    Batcher batcher;
    std::string pts;
public:
    LooseState(RenderWindow* win, std::string points) :State(win),pts(points) 
    {
        batcher.SetPrimitiveType(Lines);
        batcher.AddNumber(pts, {MAXPOSX/2-40.0f,MAXPOSY / 2},40,Color::White);
        batcher.AddRestartArrow({ MAXPOSX / 2 ,MAXPOSY / 2 +100.0f},60,Color::White);
    }
    State* OnMainLoop();
   
};

class GameState:public State
{

    PlayerSnake snake;
    FoodVec food;
    std::vector<AISnake>otherSnakes;
    float maxLifeCounter = 60.0f;
    float lifeCounter = maxLifeCounter;

    float counter = 0.0f;
    float maxCounter = 1.0f;

    int collected = 0;
    Batcher batcher;
    Clock clock;

    void OnCollected() {
        collected++;
        if (!(collected % 2))
        {
            maxCounter += 0.01f;
        }
        if (!(collected % 3))
        {
            otherSnakes.push_back(AISnake(food));
        }
        if (!(collected % 8))
        {
            maxLifeCounter *= 0.85f;
        }
        if (!(collected % 10))
        {
            snake.IncreaseSpeed(1.075f);
        }
        if (!(collected % 15))
        {
            for (size_t i = 0; i < otherSnakes.size(); i++)
            {
                otherSnakes[i].IncreaseSpeed(1.5f);
            }
        }
        lifeCounter = maxLifeCounter;
    }

public:
    GameState(RenderWindow* win):State(win)
    {
        for (size_t i = 0; i < NUMFOOD; i++)
        {
            food.AddFood();
        }
        batcher.SetPrimitiveType(Lines);
    }
    State* OnMainLoop() 
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        auto delta = clock.restart().asSeconds();

        snake.Update(delta, food);
        {
            auto headPos = snake.GetHeadPosition();
        if (headPos.x>MAXPOSX)
        {
            headPos.x = MAXPOSX;
        }
        if (headPos.y > MAXPOSY)
        {
            headPos.y = MAXPOSY;
        }
        if (headPos.x < 0)
        {
            headPos.x = 0;
        }
        if (headPos.y < 0)
        {
            headPos.y = 0;
        }
        snake.ForcePosition(headPos);
        }
        for (auto& snk : otherSnakes)
        {
            snk.Update(delta, food);


            auto headPos = snk.GetHeadPosition();
            if (headPos.x > MAXPOSX)
            {
                headPos.x = MAXPOSX;
            }
            if (headPos.y > MAXPOSY)
            {
                headPos.y = MAXPOSY;
            }
            if (headPos.x < 0)
            {
                headPos.x = 0;
            }
            if (headPos.y < 0)
            {
                headPos.y = 0;
            }
            snk.ForcePosition(headPos);
        }



        food.changed = false;
        if (food.food.size())
        {
            auto i = food.food.begin();
            while (true)
            {

                auto pos = snake.GetHeadPosition();

                auto sqrDistance = pow(i->position.x - pos.x, 2.0f) + pow(i->position.y - pos.y, 2.0f)-4.0f;
                if (sqrDistance < pow(i->GetSize(), 2.0f))
                {
                    food.changed = true;
                    i = food.food.erase(i);
                    snake.AddPoint();
                    //player caught food
                    OnCollected();
                }

                for (size_t f = 0; f < otherSnakes.size() && !food.changed; f++)
                {
                    auto pos = otherSnakes[f].GetHeadPosition();
                    auto sqrDistance = pow(i->position.x - pos.x, 2.0f) + pow(i->position.y - pos.y, 2.0f) - 4.0f;
                    if (sqrDistance < pow(i->GetSize(), 2.0f))
                    {
                        food.changed = true;
                        i = food.food.erase(i);
                        otherSnakes[f].AddPoint();
                        //otherSnake caught food
                    }

                }

                if (i == food.food.end())
                {
                    break;
                }
                else
                {
                    i++;

                    if (i == food.food.end())
                    {
                        break;
                    }
                }
            }

        }
        if (food.food.size() != NUMFOOD)
        {
            counter += delta;
            if (counter > maxCounter)
            {
                food.AddFood();
                counter -= maxCounter;
                food.changed = true;
            }
        }

        bool loose = false;

        lifeCounter -= delta;
        if (lifeCounter < 0)
        {
            loose = true;
            //loose;
        }
        

        
        window->clear();
        batcher.Clear();
        food.Draw(batcher);
        snake.Draw(batcher);
        for (auto& snk : otherSnakes)
        {
            snk.Draw(batcher);
        }
        batcher.AddPoint({ 0.0f,1.0f }, Color(240, 80, 30));
        batcher.AddPoint({ lifeCounter / maxLifeCounter * MAXPOSX,1.0f }, Color(240, 80, 30));

        auto s = IntToString(collected);
        batcher.AddNumber(s, {15.0f,MAXPOSY-30},15,Color::White);

        batcher.Draw(*window, RenderStates::Default);
        window->display();

        if (loose)
        {
            return new LooseState(window,s);
        }
        return NULL;
    }
};

State* LooseState::OnMainLoop() {
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
   
    window->clear();
    batcher.Draw(*window,RenderStates::Default);
    window->display();
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        window->close();
    }
    if (Keyboard::isKeyPressed(Keyboard::Space))
    {
        return new GameState(window);
    }
    return NULL;
}

class StartState:public State 
{
    Batcher batcher;
    Clock clock;
    float time;
public:
    StartState(RenderWindow* win) :State(win)
    {
        
        batcher.SetPrimitiveType(Lines);
        batcher.AddForwardArrow({MAXPOSX/2,MAXPOSY/2},100,Color::White);
    }
    State* OnMainLoop() {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        time += clock.restart().asSeconds();
        Transform trans;
        trans.translate({0.0f,sin(time)*10.0f});
        window->clear();
        batcher.Draw(*window, trans);
        window->display();

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window->close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            return new GameState(window);
        }
        return NULL;
    }


};

int main()
{
    {
        srand(std::time(0));
    }
    sf::RenderWindow window(sf::VideoMode(MAXPOSX, MAXPOSY), "Snakes");
    State* state= new StartState(&window);

    glLineWidth(8.0f);
    while (window.isOpen())
    {
        auto ptr=state->OnMainLoop();
        if (ptr!=NULL)
        {
            state = ptr;
        }
        
    }

    return 0;
}

