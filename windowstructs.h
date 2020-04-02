
enum WindowCompositionAttribute
{
    // ...
    WCA_ACCENT_POLICY = 19
    // ...
};

typedef struct WindowCompositionAttributeData
{
    enum WindowCompositionAttribute Attribute;
    void* Data;
    int SizeOfData;
} WindowCompositionAttributeData;

enum AccentState
{
    ACCENT_DISABLED = 0,
    ACCENT_ENABLE_GRADIENT = 1,
    ACCENT_ENABLE_TRANSPARENTGRADIENT = 2,
    ACCENT_ENABLE_BLURBEHIND = 3,
    ACCENT_INVALID_STATE = 4
};



typedef struct AccentPolicy
{
    enum AccentState AccentState;
    int AccentFlags;
    int GradientColor;
    int AnimationId;
} AccentPolicy;